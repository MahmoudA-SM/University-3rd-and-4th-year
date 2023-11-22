import java.util.List;

public interface lp_user_interface {
    void lpModel(lprec lp, int[] dimen);
    boolean isFeasible(List<List<Double>> r1, List<List<Double>> r2, List<List<Double>> r1_r2);
    double mainDiagonal(List<Integer> orderValsGreater, List<Integer> unorderedValsLess, float[][] PG, int dim, List<Double> centerMBBRet);
}
