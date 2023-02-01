public class RainbowTable
{
    public RainbowTable() {

    }

    public static void main(String[] args) {
        long res = 0;
        int i;
        String start;
        if (args != null && args.length > 0) { // Check for <input> value
            start = args[0];
            if (start.length() != 8) {
                System.out.println("Input " + start + " must be 8 characters long - Exit");
            }
            else {
//code for problem 1
                for(int f = 0; f<10000; f++)
                {
                    res = hashFunction(start);//(only doing kermit12) passing the argument into the hashfunction
                    start = reductionFunction(res, f); // then passinging the hash value and f which starts at 0 and increments by 1
                }

                System.out.println("-----Problem 1-----\n" + args[0] + " = " + start); //prints kermit12 and its end value

//code for problem 2

                        System.out.println("-----Problem 2-----");

                for(int k = 0; k<10; k++) {

                    start = args[k]; //looping through each of the ten start values

                    for (int j = 0; j < 10000; j++) { //doing 10000 iterations of the hashfunction() and the reductionFunction()

                        res = hashFunction(start); //passing in the arguments to the hash function

                        start = reductionFunction(res, j);

                        if (res == 895210601874431214L || res == 750105908431234638L || res == 111111111115664932L || res == 977984261343652499L) { //checking if the hash values is equal to the 4 hash values asked too check
                            System.out.println("hit: " + res + " " +start); //if the hash values match it prints the hash value and its end string
                        }
                    }
                }
            }
        }
        else { // No <input>
            System.out.println("Use: RainbowTable <Input>");
        }
    }

    private static long hashFunction(String s)
    {

        long ret = 0;
        int i;
        long[] hashA = new long[] {1, 1, 1, 1};
        String filler, sIn;
        int DIV = 65536;
        filler = new String("ABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGHABCDEFGH");

        sIn = s + filler; // Add characters, now have "<input>HABCDEF.

        sIn = sIn.substring(0, 64); // // Limit string to first 64 characters

        for (i = 0; i < sIn.length(); i++) {

            char byPos = sIn.charAt(i); // get i'th character

            hashA[0] += (byPos * 17111); // Note: A += B means A = A + B

            hashA[1] += (hashA[0] + byPos * 31349);

            hashA[2] += (hashA[1] - byPos * 101302);

            hashA[3] += (byPos * 79001);

        }

        ret = (hashA[0] + hashA[2]
        ) + (hashA[1] * hashA[3]
        );

        if (ret < 0) ret *= -1;

        return ret;

    }

    private static String reductionFunction(long val, int round) { // Note that for the first function call "round" has to be 0,

        String car, out;
        int i;
        char dat;

        car = new String("0123456789ABCDEFGHIJKLMNOPQRSTUNVXYZabcdefghijklmnopqrstuvwxyz!#");

        out = new String("");

        for (i = 0; i < 8; i++) {

            val -= round;

            dat = (char) (val % 63);

            val = val / 83;

            out = out + car.charAt(dat);

        }

        return out;

    }}
