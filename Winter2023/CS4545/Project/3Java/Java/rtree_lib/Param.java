public class Param {
    public static String read(int a_argc, String[] a_argv, String a_param, String a_def) {
        for (int i = 0; i < a_argc; i++) {
            if (a_argv[i].equals(a_param)) {
                if (i + 1 == a_argc)
                    return "";
                else
                    return a_argv[i + 1];
            }
        }
        return a_def;
    }
}
