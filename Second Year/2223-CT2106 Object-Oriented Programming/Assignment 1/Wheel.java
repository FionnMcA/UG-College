
public class Wheel
{

    private double radius;
    private String name;
    public Wheel(String name, double radius)
    {
        this.name = name;
        this.radius = radius;    
    }
    
    public double turn(double radius){
        return 2 * Math.PI * radius;
    }
    
    public double getRadius(){
        return radius;
    }

    public String getName(){
        return name;
    }
}
