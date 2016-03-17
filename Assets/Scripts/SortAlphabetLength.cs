public class SortAlphabetLength : System.Collections.IComparer {
    public int Compare(object x, object y)
    {
        if (x.ToString().Length == y.ToString().Length)
            return string.Compare(x.ToString(), y.ToString());
        else if (x.ToString().Length > y.ToString().Length)
            return 1;
        else
            return -1;
    }
}
