import java.awt.*;

public class GameObject {

    // member data
    private Color c;
    private int x,y;

    // Constructor
    public GameObject() {
        int red = (int)(Math.random()*256);
        int blue = (int)(Math.random()*256);
        int green = (int)(Math.random()*256);
        c = new Color(red, green, blue);
        x = (int)(Math.random()*600);
        y = (int)(Math.random()*600);
    }

    // Public Interface
    public void move() {

            x += Math.random()*5;
            x -= Math.random()*5;
            y += Math.random()*5;
            y -= Math.random()*5;


    }

    public void paint(Graphics g) {
        g.setColor(c);
        g.fillRect(x,y, 40, 40);

    }
}