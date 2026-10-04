#pragma once
#include <array>

/*     GENERAL     */

enum class CubeColor { White, Red, Blue, Orange, Green, Yellow };

enum class Face { D, F, L, B, R, U };

/*     CORNERS     */

enum Corners { UFR, URB, UBL, ULF, DFR, DRB, DBL, DLF };

struct CornerPosition { Face face[3]; };

inline const std::array<std::array<CubeColor, 3>, 8> cornerColors =
{ {
    { CubeColor::Yellow, CubeColor::Red,    CubeColor::Green  },
    { CubeColor::Yellow, CubeColor::Green,  CubeColor::Orange },
    { CubeColor::Yellow, CubeColor::Orange, CubeColor::Blue   },
    { CubeColor::Yellow, CubeColor::Blue,   CubeColor::Red    },
    { CubeColor::White,  CubeColor::Green,  CubeColor::Red    },
    { CubeColor::White,  CubeColor::Orange, CubeColor::Green  },
    { CubeColor::White,  CubeColor::Blue,   CubeColor::Orange },
    { CubeColor::White,  CubeColor::Red,    CubeColor::Blue   }
} };





/*     EDGES     */

enum Edges { UF, UR, UB, UL, DF, DR, DB, DL, FR, FL, BR, BL };

inline const std::array<std::array<CubeColor, 2>, 12> edgeColors =
{ {
    { CubeColor::Yellow, CubeColor::Red    }, 
    { CubeColor::Yellow, CubeColor::Green  },
    { CubeColor::Yellow, CubeColor::Orange }, 
    { CubeColor::Yellow, CubeColor::Blue   }, 

    { CubeColor::White,  CubeColor::Red    },
    { CubeColor::White,  CubeColor::Green  },
    { CubeColor::White,  CubeColor::Orange },
    { CubeColor::White,  CubeColor::Blue   }, 

    { CubeColor::Red,    CubeColor::Green  },
    { CubeColor::Red,    CubeColor::Blue   }, 
    { CubeColor::Orange, CubeColor::Green  }, 
    { CubeColor::Orange, CubeColor::Blue   }  
} };
