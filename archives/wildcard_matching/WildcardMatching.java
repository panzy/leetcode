package wildcard_matching;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

/**
 * Created by Zhiyong Pan on 2021-01-08.
 */
public class WildcardMatching {
    Solution solution = new Solution();

    @Test
    void example1() {
        Assertions.assertFalse(solution.isMatch("aa", "a"));
    }

    @Test
    void example2() {
        Assertions.assertTrue(solution.isMatch("aa", "*"));
    }

    @Test
    void example3() {
        Assertions.assertFalse(solution.isMatch("cb", "?a"));
    }

    @Test
    void example4() {
        Assertions.assertTrue(solution.isMatch("adceb", "*a*b"));
    }

    @Test
    void example5() {
        Assertions.assertFalse(solution.isMatch("acdcb", "a*c?b"));
    }

    @Test
    void example5_A() {
        Assertions.assertTrue(solution.isMatch("aaaaab", "a*ab"));
    }
    @Test
    void example5_B() {
        Assertions.assertTrue(solution.isMatch("aaaaab", "a*aab"));
    }
    @Test
    void example5_C() {
        Assertions.assertTrue(solution.isMatch("aaaaab", "a*aaaab"));
    }
    @Test
    void example5_D() {
        Assertions.assertFalse(solution.isMatch("aaaaab", "a*aaaaab"));
    }
    @Test
    void example5_E() {
        Assertions.assertTrue(solution.isMatch("aaabc!", "a*aabc!"));
    }
    @Test
    void example5_F() {
        Assertions.assertTrue(solution.isMatch("aaaaa", "a*a"));
    }
    @Test
    void example5_G() {
        Assertions.assertTrue(solution.isMatch("aaabc!", "a*abc!"));
    }

    @Test
    void example6() {
        Assertions.assertTrue(solution.isMatch("aaabc!", "*a*abc!"));
    }

    @Test
    void example7() {
        Assertions.assertTrue(solution.isMatch("aaabc!", "a**!"));
    }

    @Test
    void example8() {
        Assertions.assertTrue(solution.isMatch("", ""));
    }

    @Test
    void example9() {
        Assertions.assertTrue(solution.isMatch("", "*"));
    }

    @Test
    void example10() {
        Assertions.assertTrue(solution.isMatch("", "**"));
    }

    @Test
    void example11() {
        Assertions.assertTrue(solution.isMatch("abc", "a*b*****"));
    }

    @Test
    void example12() {
        Assertions.assertTrue(solution.isMatch("abcxyz", "a*b*????"));
    }

    @Test
    void example13() {
        Assertions.assertTrue(solution.isMatch("abcxyz", "a*b*?*???"));
    }

    @Test
    void example15() {
        Assertions.assertTrue(solution.isMatch("ab!@#", "a??**#"));
    }

    @Test
    void example16() {
        Assertions.assertTrue(solution.isMatch("ab!@#y#", "a*b*?*?*??#"));
    }

    @Test
    void example17() {
        Assertions.assertTrue(solution.isMatch("ab", "?*"));
    }

    @Test
    void example18() {
        Assertions.assertFalse(solution.isMatch("aaa", "aaaa"));
    }

    @Test
    void example19() {
        Assertions.assertTrue(solution.isMatch("a", "a*"));
    }

    @Test
    void example20() {
        Assertions.assertTrue(solution.isMatch("a", "*a*"));
    }

    @Test
    void example21() {
        Assertions.assertTrue(solution.isMatch("bbbba", "**a"));
    }

    @Test
    void example22() {
        Assertions.assertTrue(solution.isMatch("ab", "*??*"));
    }

    @Test
    void example23() {
        Assertions.assertTrue(solution.isMatch("aaa", "a*a**a"));
    }

    @Test
    void example24() {
        Assertions.assertTrue(solution.isMatch("aasdfasdfasdfasdfas", "aasdf*asdf*asdf*asdf*s"));
    }

    @Test
    void example25() {
        String s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        String p = "**bab****babbaabab*****bbabbbabbba***a*ababa****baba********babaabbbbbb****bababbb*****ba*bbbbababababbaabbaaba****bbababab***bbaaab****abaaaabbababbb****abaa*bababbb***babbbabaaaaa*aab*bbbaa*aaa*aba*aabb";
        Assertions.assertTrue(solution.isMatch(s, p));
    }

    @Test
    void test6() {
        String s = "mississippi";
        String p = "m??*ss*?i*pi";
        Assertions.assertFalse(solution.isMatch(s, p));
    }

    @Test
    void test1710() {
        String s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        String p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
        Assertions.assertFalse(solution.isMatch(s, p));
    }

    @Test
    void test1778() {
        // "mississippi"
        // "m??*ss*?i*pi"
        // false
        String s = "mississippi";
        String p = "m??*ss*?i*pi";
        Assertions.assertFalse(solution.isMatch(s, p));
    }
}
