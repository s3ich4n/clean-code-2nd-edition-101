/*
 * Take a look at the role and name of the function
 * "check_arg_get_dangling_opt"
 */

int check_arg_get_dangling_opt(bool *is_dangling, int _arg, char* _argv[]);

int main(int argc, char *argv[])
{
    bool is_dangling = 0;

    int checked = check_arg_get_dangling_opt(&is_dangling, argc, argv);
    if (-1 == checked){
        fprintf(stderr, "ERROR: wrong command line arguments");
        return -1;
    }

    solve(argv[1], is_dangling);
    free_graph(g)
    return 0;
}

int check_arg_get_dangling_opt(bool *is_dangling, int _arg, char* _argv[])
{
    if (_arg < 3){
        //사용법: ./main [읽을파일명] [옵션(0 or 1)]
        fprintf(stderr, "usage: ./PageRank <file_to_read> <dangling_opt>\n");
        return -1;
    }
    else{
        if (!strncmp(_argv[2], "1", 1)){
            *is_dangling = true;
        }
        else if (!strncmp(_argv[2], "0", 1)) {
            *is_dangling = false;
        }else{
            fprintf(stderr, "<dangling_opt> must be 0 or 1");
            return -1;
        }
    }
    return 0;
}
