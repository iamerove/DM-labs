import java.math.BigInteger;
import java.util.Scanner;

public class ArithmeticDecoding {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] cnt = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cnt[i] = scanner.nextInt();
            sum += cnt[i];
        }
        scanner.nextLine();
        String code = scanner.nextLine();

        int qq = code.length();
        BigInteger q = BigInteger.ONE;
        while (qq-- != 0) {
            q = q.multiply(BigInteger.TWO);
        }

        BigInteger len = BigInteger.valueOf(sum);
        BigInteger p = BigInteger.ZERO;
        for (Character c : code.toCharArray()) {
            p = p.multiply(BigInteger.TWO);
            if (c == '1') {
                p = p.add(BigInteger.ONE);
            }
        }

        BigInteger l = BigInteger.ZERO, r = BigInteger.ONE, z = BigInteger.ONE;
        StringBuilder ans = new StringBuilder();

        for (int j = 0; j < sum; j++) {
            z = z.multiply(len);
            BigInteger dif = r.subtract(l);
            int new_l = 0, new_r = 0;
            for (int i = 0; i < n; i++) {
                new_r += cnt[i];
                BigInteger cur_l, cur_r;
                cur_l = l.multiply(len);
                cur_r = cur_l.add(dif.multiply(BigInteger.valueOf(new_r)));
                cur_l = cur_l.add(dif.multiply(BigInteger.valueOf(new_l)));
                if (cur_l.multiply(q).compareTo(z.multiply(p)) != 1 && p.multiply(z).compareTo(q.multiply(cur_r)) == -1) {
                    l = cur_l;
                    r = cur_r;
                    char ch = (char) ('a' + i);
                    ans.append(ch);
                    break;
                }
                new_l += cnt[i];
            }
        }

        System.out.println(ans.toString());
    }
}
