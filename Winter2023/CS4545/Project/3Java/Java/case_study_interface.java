public interface case_study_interface {
    public double jaccard(List<Integer> ab, List<Integer> ae, List<Integer> bb, List<Integer> be);
    public double jaccard(Set<Integer> a, Set<Integer> b);
    public double precision(List<Integer> gtb, List<Integer> gte, List<Integer> rb, List<Integer> re);
    public double precision(Set<Integer> groundTruth, Set<Integer> result);
    public double recall(List<Integer> gtb, List<Integer> gte, List<Integer> rb, List<Integer> re);
    public double recall(Set<Integer> groundTruth, Set<Integer> result);
    public List<Integer> OSS_skyline(int objCnt, int r, Rtree rtree, float[][] PointSet, int dim);
}

