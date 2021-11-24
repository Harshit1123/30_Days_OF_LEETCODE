Since the processor doesn't care whether to multiply an int containing a single digit or, for example, 9, 
  we can create a solution that counts as a digit every 9 decimal digits.

Why 9? The int range is up to 2^31 - 1, that is 10^9 with remainder. This means that int can contain 9 
  
  decimal digits, that is, the maximum value stored in int will be 999_999_999
Do not forget that the multiplication 10^9 * 10^9 = 10^18, which is much larger than the range of int, but fits in long.

If we want to use only 32-bit arithmetic, we need to reduce the number of decimal digits stored in the element to 4 (10^4 * 10^4 = 10^8), 
or we need our own implementation of multiplication of 32-bit numbers that supports out-of-range (you can use the same recursively, lol). 
  Obviously, this is relevant when expanding the solution to use 64-bit numbers, since when they are multiplied, you can get a 128-bit number.

Multiplication for O(m * n) does not actually require more memory than O(m + n). 
  Additional memory appears due to the fact that the input data and the result stored in a string, while for calculations we use the int array. 
    The algorithm for multiplying numbers represented by an array requires O(1) additional memory, since intermediate calculations are written directly to the result array.
























class Solution {
    private static final int by = 9; // digits in each int element
    private static int divisor = (int) Math.pow(10, by);

    private int[] stringToArray(String number) {
        int length = number.length();
        int[] arr = new int[(length / by) + (length % by == 0 ? 0 : 1)];

        // from end to start taking _by_ digits per iteration
        for(int i = length, j = 0; i > 0; i -= by, j++) {
            // case: substring on last iteration starts from 0
            int fromIndex = Math.max(0, i - by);
            
            arr[j] = Integer.parseInt(number.substring(fromIndex, i));
        }
        
        return arr;
    }

    // numberArray is reversed so we need to traverse it in reverse order
    private String arrayToString(int[] numberArray) {
        StringBuilder resultString = new StringBuilder(numberArray.length * by);

        int lastDigitIndex = numberArray.length - 1;
        while(lastDigitIndex >= 0 && numberArray[lastDigitIndex] == 0) {
            lastDigitIndex--;
        }

        // case: all elements in array are zeros
        if(lastDigitIndex < 0) return "0";

        // append the first element without leading zeros
        resultString.append(numberArray[lastDigitIndex]);

        // append other elements with leading zeros
        for(int i = lastDigitIndex - 1; i >= 0; i--) {
            String currentDigits = Integer.toString(numberArray[i]);
            int zerosToAdd = Math.max(0, by - currentDigits.length());
            
            resultString.append("0".repeat(zerosToAdd));
            resultString.append(currentDigits);
        }

        return resultString.toString();
    }

    private int[] multiplyTwoArrays(int[] main, int[] multiplier) {
        int[] result = new int[main.length + multiplier.length];

        for(int multIndex = 0; multIndex < multiplier.length; multIndex++) {
            long carry = 0;
            
            // Multiply each element of main by current element of multiplier
            for(int mainIndex = 0; mainIndex < main.length; mainIndex++) {
                long multPair = (long) multiplier[multIndex] * main[mainIndex];

                long current = multPair +              // current multiplication
                        (carry % divisor) +            // part of carry
                        result[multIndex + mainIndex]; // part of result

                result[multIndex + mainIndex] = (int) (current % divisor);
                
                carry = (carry / divisor) + // part of carry
                    (current / divisor);    // carry of multipliication
            }

            // add carry to result after every multiplication pass
            for(int i = multIndex + main.length; carry != 0; i++) {
                long current = result[i] + (carry % divisor);
                result[i] = (int) (current % divisor);
                carry = (carry / divisor) + (current / divisor);
            }
        }

        return result;
    }

    public String multiply(String num1, String num2) {
        int[] result = multiplyTwoArrays(
            stringToArray(num1),
            stringToArray(num2)
        );
        return arrayToString(result);
    }
}
