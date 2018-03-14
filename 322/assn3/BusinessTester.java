import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BusinessTester
{
    private static void setupBusinesses ()
    {
        // the Business class will keep track all created businesses, no need to do so here.
        new Restaurant (101, "Moe's");
        new Restaurant (102, "Joe's");
        new Hotel (201, "Ritz");
        new Hotel (202, "Notel Motel");
        new ConvenienceStore (612, "Six Twelve");
    }
      
    private static void process (String filename)
    {
        try
        {
            Scanner input = new Scanner (new File (filename));
            while (input.hasNext ())
            {
                Scanner line = new Scanner (input.nextLine ());
                int accountNumber = line.nextInt ();
                boolean primary = (line.nextInt () == 1);
                double amount = line.nextDouble ();
                Business business = Business.findBusiness (accountNumber);
                if (business != null)
                {
                    if (primary)
                    {
                        business.addPrimaryIncome (amount);
                    }
                    else
                    {
                        business.addSecondaryIncome (amount);
                    }
                }
            }
            input.close ();
        }
        catch (FileNotFoundException e)
        {
            // do nothing on missing file
        }
    }
    
    public static void report ()
    {
        Business [] businesses = Business.getRegisteredBusinesses ();
        for (Business business: businesses)
        {
            System.out.println (business.report () + "\n");
        }
    }
    
    public static void main (String [] args)
    {
        setupBusinesses ();
        for (String s: args)
        {
            process (s);
        }
        report ();
    }
}