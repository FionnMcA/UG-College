
/**
 * Write a description of class TestCar here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class TestCar
{
    public static void main(String[] args){
        System.out.println("\n\n\n");
        Car car = new Car("Audi");
        Engine engine = new Engine("i8", 43);
        car.add(engine);
        Wheel wheel = new Wheel("Michelin", 15);
        car.add(wheel);
        car.setFuelLevel(100);
        System.out.printf("Current fuel: %.2f\n",car.getFuelLevel());
        car.drive();
        car.printState();
        
        car.setFuelLevel(50);
        System.out.printf("Current fuel: %.2f\n",car.getFuelLevel());
        car.drive();
        car.printState();
    }
}
