package MyApplication;
import java.awt.*;
import javax.swing.*;
public class MyApplication extends JFrame {
    private static final Dimension WindowSize = new Dimension(600, 600);

    public MyApplication() {
        this.setTitle("Assignment 1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Dimension screensize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
        int x = screensize.width / 2 - WindowSize.width / 2;
        int y = screensize.height / 2 - WindowSize.height / 2;
        setBounds(x, y, WindowSize.width, WindowSize.height);
        setVisible(true);
    }
    public void paint ( Graphics g ) {
        for(int x = 10; x <570; x+=40){ //x coordinate increasing by 40 each time allowing a gap of 10
            for(int y = 10; y < 570; y+=40){ //y coordinate increasing by 40 each time allowing a gap of 10
                //the nest loop fills all the y coordinates down to 570 at the x coordinate of value x
                colouring(g); //calls the colouring function to assign a random colour to the square
                g.fillRect(x,y,30,30); //creates a square
            }
        }
    }

    public void colouring(Graphics g){
        //creating random red green and blue values
        int red = (int)(Math.random()*256);
        int green = (int)(Math.random()*256);
        int blue  = (int)(Math.random()*256);
        g.setColor(new Color(red, green, blue)); //setting the colour to a random colour
    }

    public static void main(String [ ] args) {
        MyApplication w = new MyApplication();
    }
}
