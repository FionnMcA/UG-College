
public class Address
{
    private String street;
    private String city;
    private String zip;
    private String country;
    
    public Address(String street, String city, String zip, String country)//constructor
    {
        this.street = street;
        this.city = city;
        this.zip = zip;
        this.country = country;
    }
    
    //getters
    public String getStreet(){
        return this.street;
    }
    
    public String getCity(){
        return this.city;
    }
    
    public String getZip(){
        return this.zip;
    }
    
    public String getCountry(){
        return this.country;
    }
}
