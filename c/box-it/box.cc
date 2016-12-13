#include <iostream>

class Box {

    public:
        Box();
        Box(int,int,int);
        Box(const Box&);
        int getLength() const;
        int getBreadth() const;
        int getHeight() const;
        long long CalculateVolume() const;
        bool operator<(const Box&);
        friend std::ostream& operator<<(std::ostream&, const Box&);

    private:
        int l_;
        int w_;
        int h_;
};

Box::Box() {
    l_ = 0;
    w_ = 0;
    h_ = 0;
}

Box::Box(int l, int w, int h) {
    l_ = l;
    w_ = w;
    h_ = h;
}

Box::Box(const Box& b) {
    l_ = b.getLength();
    w_ = b.getBreadth();
    h_ = b.getHeight();
}

int Box::getLength() const {
    return l_;
}

int Box::getBreadth() const {
    return w_;
}

int Box::getHeight() const {
    return h_;
}

long long Box::CalculateVolume() const {
    return (long long)l_*w_*h_;
}

bool Box::operator<(const Box& b) {
    bool r;

    int bl = b.getLength();
    int bw = b.getBreadth();
    int bh = b.getHeight();

    if (l_ < bl) {
        r = true;
    } else if ( (w_ < bw) && (l_ == bl) ) {
        r = true;
    } else if ( (h_ < bh) && (w_ == bw) && (l_ == bl) ) {
        r = true;
    } else {
        r = false;
    }

    return r;
}

// Note: this is a friend function, not a member of Box
std::ostream& operator<<(std::ostream& os, Box& B) {
    os << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return os;
}
