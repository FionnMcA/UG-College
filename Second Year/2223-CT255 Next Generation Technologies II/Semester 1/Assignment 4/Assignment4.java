
import java.util.*;
import java.util.Random;

class Assignment4
{
    public static int Prime() { //function that generates a random prime number bewteen 10000 and 100000
        Random random = new Random();
        int c = 0;
        int n = random.nextInt(10000, 100000);

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                c++; //counts how many numbers the random number is divisible by
            }
        }

        if (c == 2) { //if its only divisible by two its a prime number
            return n;
        }
        return Prime();
    }
    static int power(int x, int y, int p)
    {
        int res = 1;     // Initialize result
        x = x % p; // Update x if it is more than or equal to p

        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y % 2 == 1)
            {
                res = (res * x) % p;
            }

            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }
    static void findPrimefactors(HashSet<Integer> s, int n)
    {
        // Print the number of 2s that divide n
        while (n % 2 == 0)
        {
            s.add(2);
            n = n / 2;
        }

        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= Math.sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                s.add(i);
                n = n / i;
            }
        }

        // This condition is to handle the case when
        // n is a prime number greater than 2
        if (n > 2)
        {
            s.add(n);
        }
    }
    static int findPrimitive(int n) { //finds the smallest primitive root
        HashSet<Integer> s = new HashSet<Integer>();

        findPrimefactors(s, n - 1);

        // Check for every number from 2 to 1 minus the prime number
        for (int r = 2; r <= n - 1; r++) {
            // Iterate through all prime factors to see if there is a power with value 1
            boolean flag = false;
            for (Integer a : s) { // Check if r^((phi)/primefactors) mod n
                if (power(r, (n - 1) / (a), n) == 1) {// is 1 or not
                    flag = true;
                    break;
                }
            }
            if (flag == false) {// If there was no power with value 1.
                return r;
            }
        }
        return -1;// If no primitive root found
    }

    public static void main(String[] args) {
        int PublicNumberP = Prime();
        int PublicNumberG = findPrimitive(PublicNumberP);

        int AlicePK = 2;
        double X = (Math.pow(PublicNumberG, AlicePK )%PublicNumberP);
        int BobPK = 3;
        double Y = (Math.pow(PublicNumberG, BobPK )%PublicNumberP);
        double KA = (Math.pow(Y, AlicePK )%PublicNumberP);
        double KB = (Math.pow(X, BobPK)%PublicNumberP);

        System.out.println("\nQuestion 1 \n");
        System.out.println("Public number P: " + PublicNumberP + "\nPublic number G: " + PublicNumberG);
        System.out.println("Alice private key: " + AlicePK);
        System.out.println("Bob private key: " + BobPK);

        System.out.println("\nAlice: X = (G^a mod P): " + X + " = (" + PublicNumberG + "^2" + " % " + PublicNumberP + ")");
        System.out.println("Bob: X = (G^b mod P): " + Y + " = (" + PublicNumberG + "^3" + " % " + PublicNumberP + ")");

        System.out.println ("\nAlice: ka = (y^a mod P): " + Y + "^" + AlicePK + " mod " + PublicNumberP + " = " + KA);
        System.out.println ("Bob: kb = (x^b mod P): " + X + "^" + BobPK + " mod " + PublicNumberP + " = " + KB);

        //MitM attack

        System.out.println("\nQuestion 2 MitM attack\n");

        int Malory = 1;
        double YM = (Math.pow(PublicNumberG, Malory )%PublicNumberP);

        double KA2 = (Math.pow(YM, AlicePK )%PublicNumberP);
        double KB2 = (Math.pow(YM, BobPK )%PublicNumberP);

        System.out.println("Public number P: " + PublicNumberP + "\nPublic number G: " + PublicNumberG);
        System.out.println("Alice private key: " + AlicePK);
        System.out.println("Bob private key: " + BobPK);
        System.out.println("Malory: " + Malory);

        System.out.println("\nALice recieves " + YM + " and calculates K as follow: K =  " + YM + "^" + AlicePK + " mod " + PublicNumberP + " = " + KA2);

        double MaloryKA = (Math.pow(KA2, Malory)%PublicNumberP);
        System.out.println("Malory calculates " + KA2 + "^" + Malory + " mod " + PublicNumberP + " = "  + MaloryKA);

        System.out.println("\nBob recieves " + YM + " and calculates K as follow: K =  " + YM + "^" + BobPK + " mod " + PublicNumberP + " = " + KB2);
        double MaloryKB = (Math.pow(KB2, Malory)%PublicNumberP);
        System.out.println("Malory calculates " + KB2 + "^" + Malory + " mod " + PublicNumberP + " = "  + MaloryKB);
    }
}