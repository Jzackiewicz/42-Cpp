#include "Swap.hpp"
#include <cassert>

// Helper to create a file with given content
void createFile(const std::string& filename, const std::string& content = "") {
    std::ofstream ofs(filename.c_str());
    ofs << content;
    ofs.close();
}

// Helper to remove a file
void removeFile(const std::string& filename) {
    std::remove(filename.c_str());
}

// Helper to read file content as a string
std::string readFile(const std::string& filename) {
    std::ifstream ifs(filename.c_str());
    std::string content, line;
    while (std::getline(ifs, line)) {
        content += line + "\n";
    }
    return content;
}

// Existing input tests...

void test_empty_filename() {
    assert(!checkInput("", "test"));
    std::cout << "\033[32mtest_empty_filename passed\033[0m\n";
}

void test_empty_s1() {
    assert(!checkInput("somefile.txt", ""));
    std::cout << "\033[32mtest_empty_s1 passed\033[0m\n";
}

void test_nonexistent_file() {
    assert(!checkInput("nonexistent.txt", "test"));
    std::cout << "\033[32mtest_nonexistent_file passed\033[0m\n";
}

void test_empty_file() {
    std::string fname = "emptyfile.txt";
    createFile(fname);
    assert(!checkInput(fname, "test"));
    removeFile(fname);
    std::cout << "\033[32mtest_empty_file passed\033[0m\n";
}

void test_valid_file_and_s1() {
    std::string fname = "validfile.txt";
    createFile(fname, "hello\n");
    assert(checkInput(fname, "hello"));
    removeFile(fname);
    std::cout << "\033[32mtest_valid_file_and_s1 passed\033[0m\n";
}

// Logic tests

void test_replace_single_line_exact_match() {
    std::string fname = "file1.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "foo\n");
    findAndReplace(fname, "foo", "bar");
    std::string result = readFile(outname);
    assert(result == "bar\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_single_line_exact_match passed\033[0m\n";
}

void test_replace_single_line_no_match() {
    std::string fname = "file2.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "hello\n");
    findAndReplace(fname, "foo", "bar");
    std::string result = readFile(outname);
    assert(result == "hello\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_single_line_no_match passed\033[0m\n";
}

void test_replace_multiple_lines_some_match() {
    std::string fname = "file3.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "foo\nbaz\nfoo\n");
    findAndReplace(fname, "foo", "bar");
    std::string result = readFile(outname);
    assert(result == "bar\nbaz\nbar\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_multiple_lines_some_match passed\033[0m\n";
}

void test_replace_multiple_lines_all_match() {
    std::string fname = "file4.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "foo\nfoo\nfoo\n");
    findAndReplace(fname, "foo", "bar");
    std::string result = readFile(outname);
    assert(result == "bar\nbar\nbar\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_multiple_lines_all_match passed\033[0m\n";
}

void test_replace_empty_s2() {
    std::string fname = "file5.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "foo\nbaz\nfoo\n");
    findAndReplace(fname, "foo", "");
    std::string result = readFile(outname);
    assert(result == "\nbaz\n\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_empty_s2 passed\033[0m\n";
}

void test_replace_no_lines_match() {
    std::string fname = "file6.txt";
    std::string outname = fname + ".replace";
    createFile(fname, "abc\ndef\nghi\n");
    findAndReplace(fname, "foo", "bar");
    std::string result = readFile(outname);
    assert(result == "abc\ndef\nghi\n");
    removeFile(fname);
    removeFile(outname);
    std::cout << "\033[32mtest_replace_no_lines_match passed\033[0m\n";
}

int main() {
    // Input validation tests
    test_empty_filename();
    test_empty_s1();
    test_nonexistent_file();
    test_empty_file();
    test_valid_file_and_s1();

    // Logic tests
    test_replace_single_line_exact_match();
    test_replace_single_line_no_match();
    test_replace_multiple_lines_some_match();
    test_replace_multiple_lines_all_match();
    test_replace_empty_s2();
    test_replace_no_lines_match();

    std::cout << "\033[32mAll tests passed.\033[0m\n";
    return 0;
}
