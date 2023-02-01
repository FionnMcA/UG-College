import java.util.Random; //import the random utility

public class Customer{
    private String firstName;
    private String surName;
    private String emailAddress;
    private final long customerId;
    
    public Customer(String firstName, String surName, String emailAddress) //Customer constructor
    {
        this.firstName = firstName;
        this.surName = surName;
        this.emailAddress = emailAddress;
        customerId = makeCustomerId();
    
    }
    
    public long makeCustomerId(){ // a method to randomly create a customer ID
        Random random = new Random();
        return (long) random.nextInt(1000000000);
    }
    
    //getters
    public long getId(){
        return customerId;
    }
    
    public String getFirstName(){
        return firstName;
    }
    
    public String getSurName(){
        return surName;
    }
    
    public String getEmailAddress(){
        return emailAddress;
    }
    
}
