#ifndef HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_
#define HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_

struct PosTime
{
	constexpr static int maxStrLen = 20;
	PosTime();
	char lat[maxStrLen];
	char lon[maxStrLen];
	char time[maxStrLen];
	void clear();
	bool hasData() const;
	operator bool() const;
};

class NMEAParser
{
public:
	void parse(const char* str);
	const PosTime& result() const;

private:
	PosTime m_result;
};


#endif /* HIGH_LEVEL_INCLUDE_NMEA_PARSER_HPP_ */
