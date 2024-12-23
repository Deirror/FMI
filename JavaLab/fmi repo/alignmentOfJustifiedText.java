import java.util.Arrays;

public class TextJustifier {
    public static String[] justifyText(String[] words, int maxWidth) {
        StringBuilder[] modifiedWords = new StringBuilder[words.length];

        for (int i = 0; i < words.length; i++) {
            modifiedWords[i] = new StringBuilder();
            modifiedWords[i].append(words[i]);
        }

        int startIndex = 0;
        int currentWidth = words[0].length();
        int countCurrWords = 1;

        if(currentWidth > maxWidth) {
            return null;
        }

        for(int i = 1; i < words.length; i++) {
            if(words[i].length() > maxWidth) {
                return null;
            }

            if(currentWidth + words[i].length() + countCurrWords <= maxWidth) {
                currentWidth += words[i].length();
                countCurrWords++;
            } else {
                int spacesToAdd = maxWidth - currentWidth;
                int till =  countCurrWords - 1;
                if(till == 0) till = 1;

                for(int j = 0, t = startIndex; j < spacesToAdd;) {
                    if(t - startIndex < till) {
                        modifiedWords[t].append(' ');
                        t++;
                        j++;
                    } else {
                        t = startIndex;
                    }
                }
                startIndex = i;
                currentWidth = words[i].length();
                countCurrWords = 1;
            }
        }

        StringBuilder result = new StringBuilder();
        for(int i = 0; i < startIndex; i++) {
            result.append(modifiedWords[i]);

            if(!modifiedWords[i].toString().contains(" ") || modifiedWords[i].length() == maxWidth) {
                result.append('#');
            }
        }

        int len = 0;
        for(int i = startIndex; i < words.length; i++) {
            result.append(words[i]);
            result.append(' ');
            len += words[i].length() + 1;
        }

        int spacesToAdd = maxWidth - len;
        for(int i = 0; i < spacesToAdd; i++) {
            result.append(' ');
        }

        return result.toString().split("#");
    }
}
