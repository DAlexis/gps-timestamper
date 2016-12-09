/*
 * string-utils.h
 *
 *  Created on: 9 дек. 2016 г.
 *      Author: dalexies
 */

#ifndef GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_H_
#define GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_H_

#ifdef __cplusplus
	extern "C" {
#endif

int double2str(char* buffer, double value, unsigned int precision, unsigned int maxBufferLen);

#ifdef __cplusplus
	}
#endif

#endif /* GPS_TIMESTAMPER_HIGH_LEVEL_INCLUDE_STRING_UTILS_H_ */
