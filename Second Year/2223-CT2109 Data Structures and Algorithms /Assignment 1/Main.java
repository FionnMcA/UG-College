import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("Type the alphabet in order (hit enter between the letters)");
        System.out.println("Forwards or Backwards (f/b): ");
        Scanner scanner = new Scanner(System.in);
        String answer = scanner.nextLine(); //reads in the user's string input
        char[] alphabet = "abcdefghijklmnopqrstuvwxyz".toCharArray(); //creates array of alphabet

        if(answer.equals("f") || answer.equals("F")){ //if the user entered f/F
            long startTime = System.nanoTime(); //start timer

            for(int i = 0; i < alphabet.length; i++){ //loop through alphabet from start to finish
                char letter = scanner.next().charAt(0); //letter the user entered
                if(letter == alphabet[i] && i == alphabet.length-1){ //if it's the correct letter and the last letter of the alphabet
                    System.out.println("Correct well done");
                    break;
                }
                else if(letter == alphabet[i] && i != alphabet.length-1){ //if it's correct letter and not the last letter of the alphabet
                    System.out.println(alphabet[i] + " Correct now type " + alphabet[i+1]);
                }
                else if (letter != alphabet[i]){ //if the letter is incorrect
                    i--; //decrement the i counter so the loop loops the correct 26 letters
                }
            }

            long endTime = System.nanoTime(); //end the recording
            long duration = (endTime - startTime)/1000000000; //calculate the time in seconds
            System.out.println("Time = " + duration + "seconds");
        }

        if(answer.equals("b") || answer.equals("B")){
            long startTime = System.nanoTime();

            for(int i = alphabet.length-1; i >= 0; i--){ //starting from the last index of the array looping to the start
                char letter = scanner.next().charAt(0);

                if(letter == alphabet[i] && i != 0){
                    System.out.println(alphabet[i] + " Correct now type " + alphabet[i-1]);
                }
                else if(letter == alphabet[i] && i == 0){
                    System.out.println("Correct well done");
                    break;
                }

                else if (letter != alphabet[i]){
                    i++; //if the letter is incorrect increment the counter so it loops the correct 26 letters
                }
            }

            long endTime = System.nanoTime();
            long duration = (endTime - startTime)/1000000000;
            System.out.println("Time = " + duration + "seconds");

        }
    }
}