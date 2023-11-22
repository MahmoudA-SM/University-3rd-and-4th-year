import java.util.List;

public interface qp_solver2Interface {
    List<Float> findPointInRegion(List<Float> w, List<List<Double>> H);
    List<Double> findPointInRegion(List<Float> w, List<List<Double>> H1, List<List<Double>> H2);
    double qpSolver2(List<Float> w, List<List<Double>> H);
    double qpSolver2(List<Float> w, List<List<Double>> H1, List<List<Double>> H2);
    double qpSolver2(List<Float> w, List<List<Double>> H1, int opt, List<Integer> cmp, float[][] PG);
    double qpSolver2(List<Float> w, List<List<Double>> H1, int opt, List<Integer> cmp, float[][] PG, List<Double> retv);
}
