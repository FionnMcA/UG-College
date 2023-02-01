import java.awt.*;
import javax.print.attribute.standard.NumberOfDocuments;
import javax.swing.*;


public class MovingSquaresApplication extends JFrame implements Runnable {

    private static final Dimension WindowSize = new Dimension(600,600);
    private static final int NUMGAMEOBJECTS = 30;
    private GameObject[] GameObjectArray = new GameObject[NUMGAMEOBJECTS];

    public MovingSquaresApplication(){
        this.setTitle("Threads and Animation");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Dimension screensize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
        int x = screensize.width / 2 - WindowSize.width / 2;
        int y = screensize.height / 2 - WindowSize.height / 2;
        setBounds(x, y, WindowSize.width, WindowSize.height);
        setVisible(true);

        for(int i = 0; i < NUMGAMEOBJECTS; i++){
            GameObjectArray[i] = new GameObject();
        }

        Thread thread = new Thread(this);
        thread.start();
    }

    public void run() {
        while(true) {
            try {
                Thread.sleep(250);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            for (int k = 0; k < NUMGAMEOBJECTS; k++) {
                GameObjectArray[k].move();
                this.repaint();
            }
        }
    }

    public void paint (Graphics g) {
        g.setColor(Color.white);
        g.fillRect(0,0,10000, 100000);
        for(int i = 0; i < NUMGAMEOBJECTS; i++){
            GameObjectArray[i].paint(g);
        }
    }

    public static void main(String[] args){
        MovingSquaresApplication w = new MovingSquaresApplication();
    }

}
