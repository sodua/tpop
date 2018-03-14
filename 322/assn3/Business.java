import java.util.ArrayList;

public abstract class Business
{
    private int accountNumber;
    private double primaryIncome, secondaryIncome;
    private String businessName;
   
    public Business(int accountNumber, String name)
    {
        this.accountNumber = accountNumber;
        this.name = name;
    }   
    
    public int getAccountNumber()
    {
        return accountNumber;
    }

    public void setAccountNumber(int newAccountNumber)
    {
        accountNumber = newAccountNumber;
    }

    public String getName()
    {
        return name;
    }

    public void setName(String newName)
    {
        name = newName;
    }

    public double getPrimaryIncome()
    {
        return primaryIncome;
    }

    public double getSecondaryIncome()
    {
        return secondaryIncome;
    }

    public void addPrimaryIncome(double amount)
    {
        primaryIncome += amount;
    }

    public void addSecondaryIncome(double amount)
    {
        secondaryIncome += amount;
    }

    abstract public abstract double getTaxDue();

    abstract public String report();

    public static Business[] getRegisteredBusinesses()
    {

    }

    public static Business findBusiness(int accountNumber)
    {

    }

}

//Hotel subclass of the Business class.

public class Hotel extends Business 
{
    public Hotel(int accountNumber, String name)
    {
        account_number = accountParameter;
    }
    public double getTaxDue()
    {
        if (occupancy_rate > .9)
        {
            high_occ_tax = .02 * receipts_amount;
        }
        else
        {
            high_occ_tax = 0;
        }
        receipts_tax = .06 * receipts_amount;
        total_tax_due = high_occ_tax + receipts_tax;
        return total_tax_due;
    }
    
    public String report()
    {
        return ("Account Number: " + getAccountNumber() + "\n" + 
                "Business Type: Hotel\n" +
                "Room Income: $" + getPrimaryIncome() + "\n" +
                "Suite Income: $" + getSecondaryIncome() + "\n" +
                "Total Income: $" + (getPrimaryIncome() + getSecondaryIncome()) + "\n" +
                "Total Tax Due: $" + getTaxDue() 
        );
    }
    
}

//Restaurant subclass of the Business class.

class Restaurant extends Business
{
    private int account_number;
    private double bar_tax, food_tax, drink_tax, tax_due, food_receipt, drink_receipt, total_due;
   
    public Restaurant(int accountParameter)
    {
        account_number = accountParameter;
    }
    public Restaurant(int accountParameter, double foodRecParameter, double drinkRecParameter)
    {
        account_number = accountParameter;
        drink_receipt = drinkRecParameter;
        food_receipt = foodRecParameter;
    }
    public void setFoodReceipt(double foodRecParameter)
    {
        food_receipt = foodRecParameter;
    }
    public void setDrinkReceipt(double drinkRecParameter) 
    {
        drink_receipt = drinkRecParameter;
    }
    public double getFoodReceipt()
    {
        return food_receipt;
    }
    public double getDrinkReceipt()
    {
        return drink_receipt;
    }
    public double calculateTax()
    {
        if (food_receipt < drink_receipt)
        {
            bar_tax = .03 * (drink_receipt + food_receipt);
        }
        else
        {
            bar_tax = 0;
        }
        drink_tax = .08 * drink_receipt;
        tax_due = bar_tax + drink_tax;
        return tax_due;
    }
    public String print(double taxParameter)
    {
        return ("The restaurant number is " + account_number + ", food receipts are "
                +  food_receipt + ", and drink receipts are " + drink_receipt + ". The total tax is " + taxParameter);
    }
}


//ConvenienceStore subclass of the Business class parent class.

class ConvenienceStore extends Business
{
    private int account_number;
    private double other_receipts, newspaper_receipts,tax_due;
    public ConvenienceStore(int accountParameter)
    {
        account_number = accountParameter;
    }
    public ConvenienceStore(int accountParameter, double otherParameter,double newsParameter)
    {
        account_number = accountParameter;
        other_receipts = otherParameter;
        newspaper_receipts = newsParameter;
        
    }
    public void setOtherReceipts(double otherParameter)
    {
        other_receipts = otherParameter;
    }
    public void setNewsReceipts(double newsParameter)
    {
        newspaper_receipts = newsParameter;
    }
    public double getOtherReceipts()
    {
        return other_receipts;
    }
    public double getNewsReceipts()
    {
        return newspaper_receipts;
    }
    public double calculateTax()
    {
        tax_due = .07 * other_receipts;
        return tax_due;
    }
    public String print(double taxParameter)
    {
        return ("The account number is " + account_number + ", newspaper receipts " + newspaper_receipts +
                    ", other receipts " + other_receipts + ". The tax due is " + taxParameter);
        
    }
}
