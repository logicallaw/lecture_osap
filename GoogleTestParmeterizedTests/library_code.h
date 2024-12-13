
class Validator {
public:
	Validator(int low, int high);
	bool InRange(int value_to_test) const;

private:
	int low_, high_;
};
