
public class Car
{
    private String name;
    private float distance;
    private Engine engine;
    private Wheel wheel;
    private float totalKm;
    private float distanceTravelled;
    private float TotalDistance;
    
    public Car(String name){
        this.name = name;
        
    }
    
    public void drive(){
        float MaxFuel = engine.getFuelLevel();
        distance = 0;
        for(int i = 0; i < MaxFuel; i++){
        distance += (engine.getTpl())*(wheel.turn(wheel.getRadius()));
        engine.setFuelLevel((int)engine.getFuelLevel() - 1);
    }
        distanceTravelled += distance;
        TotalDistance += distanceTravelled;
    }
    
    public void printState(){
        System.out.println("Configuration: Car bosy: " + name);
        System.out.println("Engine name: " + engine.getName());
        System.out.println("Engine turns per litre: " + engine.getTpl());
        System.out.println("Wheel name: " + wheel.getName());
        System.out.println("Wheel radius: " + wheel.getRadius());
        System.out.println("Wheel circumference (distance per turn): " + wheel.turn(wheel.getRadius()));
        System.out.println("Distance this trip: " + distanceTravelled);
        System.out.println("Total Distamce travlled: " + TotalDistance);
        System.out.println("Current fuel status: " + engine.getFuelLevel());
        
        
    }
    
    public void setFuelLevel(float fuelLevel){
        this.engine.setFuelLevel((int) fuelLevel);
    }
    
    public float getFuelLevel(){
        return engine.getFuelLevel();
    }
    public String getName(){
        return name;
    }
    
    void add(Engine engine){
        this.engine = engine;
    }
    
    void add(Wheel wheel){
        this.wheel = wheel;
    }
}
