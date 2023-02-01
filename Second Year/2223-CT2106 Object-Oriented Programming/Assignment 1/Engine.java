
public class Engine
{
 
    private String name;
    private Wheel wheel;
    private float tpl;
    private float totalNumTurns;
    private float fuelLevel;
    
    public Engine(String name, float tpl)
    {
       this.name = name;
       this.tpl = tpl;
    }
    
    public void setFuelLevel(int fuelLevel){
        this.fuelLevel = fuelLevel;
    }
    
    public float getFuelLevel(){
        return fuelLevel;
    }
    public String getName(){
        return name;
    }

    public float getTpl(){
        return tpl;
    }
    
    public float getTotalNumTurns(){
        return totalNumTurns;
    }
}
