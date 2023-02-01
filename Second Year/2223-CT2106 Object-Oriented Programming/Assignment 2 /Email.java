
import java.util.ArrayList;

public class Email
{
    private Order order;
    
    public Email(Order order)//and email has an order
    {
        //this.customer = customer;
        this.order = order;
    }
    
    public void successfulEmail(){ //prints all the information about the order and tells the customer it was successful
        System.out.println("\nEmail: to " + order.getCustomer().getEmailAddress());
        System.out.println("Congrats " + order.getCustomer().getFirstName() + " " + order.getCustomer().getSurName() + ". Your order #"+ order.getOrderID() + " has been successful");
        System.out.println("Yoiur customer ID was " + order.getCustomer().getId());
        System.out.println("Your order was:");
        order.printOrder();
        System.out.println("Your billing address was " + order.getBilling().getStreet() + ", " + order.getBilling().getCity() + ", " +order.getBilling().getZip() + ", " + order.getBilling().getCountry());
        System.out.println("Your order will be delivered to: " + order.getDelivery().getStreet() + ", " + order.getDelivery().getCity() + ", " +order.getDelivery().getZip() + ", " + order.getDelivery().getCountry() + " within the next 5 to 7 working days");
    }
    
    public void unsuccessfulEmail(){ //tells the customer their order was unsuccessful
        System.out.println("\nEmail to : " + order.getCustomer().getEmailAddress());
        System.out.println("Sorry " + order.getCustomer().getFirstName() + " " + order.getCustomer().getSurName() + " we could not process your order #" + order.getOrderID() +" please try again and ensure the correct details are filled out");
    }   
}
