/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */
import java.io.*;
import java.util.*;

public class tarea {
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());

        int digits = 1;
        int pow = 1;
        int row = 0;
        int col = 0;
        int pages = 1;
        for (int i = 1; i <= N; ++i) {
            if (pow * 10 == i) {
                pow = i;
                digits += 1;
            }
            if (col + digits > 28) {
                col = 0;
                row += 1;
            }
            if (row == 35) {
                row = 0;
                pages += 1;
            }
            col += digits;
        }
        if (row == 0 && col == 0)
            pages -= 1;

        System.out.println(pages);
    }
}
