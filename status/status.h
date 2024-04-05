#ifndef STATUS_STATUS_H
#define STATUS_STATUS_H

// Use constexpr instead of macro.
inline constexpr int kTrue = 1;
inline constexpr int kFalse = 0;
inline constexpr int kOK = 1;
inline constexpr int kError = 0;
inline constexpr int kInfeasible = -1;
inline constexpr int kOverflow = -2;

// Use using instead of typedef.
using Status = int;


#endif /* STATUS_STATUS_H */
