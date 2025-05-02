#include "IOAble.h"

namespace seneca {

    class Box : public seneca::IOAble {
        int m_height, m_width;
    public:
        Box(int height = 0, int width = 0);
        virtual std::ostream& write(std::ostream& ostr) const override;
        virtual std::istream& read(std::istream& istr) override;
        virtual ~Box();
    };

    Box::Box(int height, int width) : m_height(height), m_width(width) {}

    std::ostream& Box::write(std::ostream& ostr) const {
        // Custom implementation for Box
        return ostr << "Box [Height: " << m_height << ", Width: " << m_width << "]";
    }

    std::istream& Box::read(std::istream& istr) {
        // Custom implementation for Box
        return istr >> m_height >> m_width;
    }

    Box::~Box() {}

    // Define the operator overloads within the global namespace
    std::ostream& operator<<(std::ostream& ostr, const seneca::IOAble& obj) {
        return obj.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, seneca::IOAble& obj) {
        return obj.read(istr);
    }
}
