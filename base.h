#include <string>

class BaseConvert{

    public:
        BaseConvert();
        BaseConvert(int base1, int base2);
        std::string operator()(std::string input) const;

    private:
        int baseFrom;
        int baseTo;

        int ToBaseTen(std::string input) const;
        std::string ToCustomBase(int input) const;
};
