#define FILE_IO

#include <cstdio>

namespace hermione {

int scan();
template <typename Type, typename... Args> int read(Type&, Args&...);
int token(char*);
template <typename Type> int lread(Type*, const int&);
template <typename Type, typename... Args> void print(const Type&, const Args&...);
template <typename Type> void lprint(Type* arr, const int& length);

int a[1000];

int main(int argc, char** argv) {
  int t = scan();
  while (t--) {
    int n = scan();
    int ans = 0xffffffff;
    for (int i = 0; i < n; ++i) {
      ans &= scan();
    }
    print(ans, '\n');
  }
  return 0;
}

#ifndef TYPE_LESS_IO_
#define TYPE_LESS_IO_

#define mread(format) return std::scanf("%" format, &x)

int read(char& x) { return std::scanf(" %c", &x); }
int read(unsigned char& x) { mread("hhu"); }
int read(short& x) { mread("hd"); }
int read(unsigned short& x) { mread("hu"); }
int read(int& x) { mread("d"); }
int read(unsigned int& x) { mread("u"); }
int read(long& x) { mread("ld"); }
int read(unsigned long& x) { mread("lu"); }
int read(long long& x) { mread("lld"); }
int read(unsigned long long& x) { mread("llu"); }
int read(float& x) { mread("f"); }
int read(double& x) { mread("lf"); }
int read(long double& x) { mread("Lf"); }
int read(void*& x) { mread("p"); }
int read(char* x) { return std::scanf(" %s", x); }
int read() { return 0; }

template <typename Type>
void read(const Type& x) { throw "read type error"; }

template <typename Type, typename... Args>
int read(Type& x, Args&... args) {
  return read(x) != EOF ? read(args...) : EOF;
}

int token(char* x) { return std::scanf("%s", x); }

template <typename Type>
int lread(Type* arr, const int& length) {
  int ret = 0;
  for (int i = 0; i < length; ++i) {
    ret = read(arr[i]);
  }
  return ret;
}

int scan() {
  int x; read(x);
  return x;
}

#define mprint(format) std::printf("%" format, x)

void print(const char& x) { mprint("c"); }
void print(char* x) { mprint("s"); }
void print(const char* x) { mprint("s"); }
void print(const unsigned char& x) { mprint("hhu"); }
void print(const short& x) { mprint("hd"); }
void print(const unsigned short& x) { mprint("hu"); }
void print(const int& x) { mprint("d"); }
void print(const unsigned int& x) { mprint("u"); }
void print(const long& x) { mprint("ld"); }
void print(const unsigned long& x) { mprint("lu"); }
void print(const long long& x) { mprint("lld"); }
void print(const unsigned long long& x) { mprint("llu"); }
void print(const double& x) { mprint("le"); }
void print(const long double& x) { mprint("Le"); }
void print(void* x) { mprint("p"); }
void print() {}

template <typename Type>
void print(const Type& x) { throw "print type error"; }

template <typename Type, typename... Args>
void print(const Type& x, const Args&... args) {
  print(x); print(args...);
}

template <typename Type>
void lprint(Type* arr, const int& length) {
  for (int i = 0; i < length; ++i) {
    print(arr[i]);
    print(i == length - 1 ? '\n' : ' ');
  }
}
void lprint(char* arr, const int& length) {
  for (int i = 0; i < length; ++i) { print(arr[i]); }
  print('\n');
}

class typeof_print_LF_before_EOF {
public:
  ~typeof_print_LF_before_EOF() { print('\n'); }
} print_LF_before_EOF;

#endif // ifndef TYPE_LESS_IO_

} // namespace hermione

int main(int argc, char** argv) {
  #if defined(DEBUG) && defined(FILE_IO)
  (std::freopen("test.in", "r", stdin));
  (std::freopen("test.out", "w", stdout));
  #endif
  int ret = hermione::main(argc, argv);
  #if defined(DEBUG) && defined(FILE_IO)
  (std::fclose(stdin));
  (std::fclose(stdout));
  #endif
  return ret;
}