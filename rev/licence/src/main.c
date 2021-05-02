#include <stdio.h>
#include <string.h>

int check(char *flag) {
  if ((flag[0] ^ flag[11]) == 126) {
    return 1;
  }
  if ((flag[0] + flag[45]) == 128) {
    return 1;
  }
  if ((flag[0] - flag[28]) == 24) {
    return 1;
  }
  if ((flag[0] ^ 29) == 91) {
    if ((flag[1] - flag[13]) == 26) {
      return 1;
    }
    if ((flag[1] - flag[18]) == 33) {
      return 1;
    }
    if ((flag[1] ^ flag[17]) == 52) {
      return 1;
    }
    if ((flag[1] - flag[0]) == 6) {
      if ((flag[2] - flag[9]) == -28) {
        return 1;
      }
      if ((flag[2] ^ flag[36]) == 114) {
        return 1;
      }
      if ((flag[2] - flag[28]) == 17) {
        return 1;
      }
      if ((flag[2] ^ flag[1]) == 13) {
        if ((flag[3] + flag[43]) == 194) {
          return 1;
        }
        if ((flag[3] - flag[17]) == -40) {
          return 1;
        }
        if ((flag[3] - flag[24]) == 26) {
          return 1;
        }
        if ((flag[3] ^ flag[2]) == 6) {
          if ((flag[4] - flag[42]) == 26) {
            return 1;
          }
          if ((flag[4] ^ flag[22]) == 73) {
            return 1;
          }
          if ((flag[4] + flag[3]) == 198) {
            return 1;
          }
          if ((flag[4] ^ flag[3]) == 60) {
            if ((flag[5] + flag[7]) == 108) {
              return 1;
            }
            if ((flag[5] ^ flag[0]) == 122) {
              return 1;
            }
            if ((flag[5] ^ flag[59]) == 0) {
              return 1;
            }
            if ((flag[5] ^ flag[4]) == 79) {
              if ((flag[6] ^ flag[28]) == 92) {
                return 1;
              }
              if ((flag[6] - flag[27]) == 3) {
                return 1;
              }
              if ((flag[6] - flag[6]) == 5) {
                return 1;
              }
              if ((flag[6] ^ flag[5]) == 90) {
                if ((flag[7] - flag[1]) == -18) {
                  return 1;
                }
                if ((flag[7] + flag[31]) == 176) {
                  return 1;
                }
                if ((flag[7] ^ flag[19]) == 65) {
                  return 1;
                }
                if ((flag[7] - flag[6]) == -56) {
                  if ((flag[8] - flag[32]) == 6) {
                    return 1;
                  }
                  if ((flag[8] ^ flag[50]) == 10) {
                    return 1;
                  }
                  if ((flag[8] - flag[10]) == 75) {
                    return 1;
                  }
                  if ((flag[8] ^ flag[7]) == 68) {
                    if ((flag[9] ^ flag[36]) == 103) {
                      return 1;
                    }
                    if ((flag[9] + flag[54]) == 155) {
                      return 1;
                    }
                    if ((flag[9] ^ flag[15]) == 104) {
                      return 1;
                    }
                    if ((flag[9] - flag[8]) == -19) {
                      if ((flag[10] - flag[2]) == -7) {
                        return 1;
                      }
                      if ((flag[10] ^ flag[62]) == 180) {
                        return 1;
                      }
                      if ((flag[10] + flag[34]) == 107) {
                        return 1;
                      }
                      if ((flag[10] ^ flag[9]) == 110) {
                        if ((flag[11] + flag[0]) == 126) {
                          return 1;
                        }
                        if ((flag[11] - flag[50]) == -55) {
                          return 1;
                        }
                        if ((flag[11] + flag[35]) == 162) {
                          return 1;
                        }
                        if ((flag[11] + flag[10]) == 102) {
                          if ((flag[12] ^ flag[57]) == 60) {
                            return 1;
                          }
                          if ((flag[12] ^ flag[53]) == 221) {
                            return 1;
                          }
                          if ((flag[12] + flag[23]) == 218) {
                            return 1;
                          }
                          if ((flag[12] + flag[11]) == 148) {
                            if ((flag[13] ^ flag[39]) == 2) {
                              return 1;
                            }
                            if ((flag[13] ^ flag[44]) == 12) {
                              return 1;
                            }
                            if ((flag[13] + flag[59]) == 108) {
                              return 1;
                            }
                            if ((flag[13] - flag[12]) == -43) {
                              if ((flag[14] - flag[15]) == 47) {
                                return 1;
                              }
                              if ((flag[14] - flag[59]) == 51) {
                                return 1;
                              }
                              if ((flag[14] ^ flag[45]) == 100) {
                                return 1;
                              }
                              if ((flag[14] ^ flag[13]) == 107) {
                                if ((flag[15] ^ flag[49]) == 2) {
                                  return 1;
                                }
                                if ((flag[15] ^ flag[39]) == 13) {
                                  return 1;
                                }
                                if ((flag[15] ^ flag[47]) == 65) {
                                  return 1;
                                }
                                if ((flag[15] ^ flag[14]) == 106) {
                                  if ((flag[16] + flag[38]) == 218) {
                                    return 1;
                                  }
                                  if ((flag[16] + flag[32]) == 231) {
                                    return 1;
                                  }
                                  if ((flag[16] + flag[59]) == 166) {
                                    return 1;
                                  }
                                  if ((flag[16] ^ flag[15]) == 64) {
                                    if ((flag[17] ^ flag[11]) == 77) {
                                      return 1;
                                    }
                                    if ((flag[17] - flag[19]) == -1) {
                                      return 1;
                                    }
                                    if ((flag[17] + flag[60]) == 162) {
                                      return 1;
                                    }
                                    if ((flag[17] + flag[16]) == 229) {
                                      if ((flag[18] ^ flag[54]) == 5) {
                                        return 1;
                                      }
                                      if ((flag[18] - flag[4]) == -64) {
                                        return 1;
                                      }
                                      if ((flag[18] ^ flag[9]) == 87) {
                                        return 1;
                                      }
                                      if ((flag[18] - flag[17]) == -61) {
                                        if ((flag[19] + flag[56]) == 177) {
                                          return 1;
                                        }
                                        if ((flag[19] ^ flag[6]) == 29) {
                                          return 1;
                                        }
                                        if ((flag[19] + flag[11]) == 168) {
                                          return 1;
                                        }
                                        if ((flag[19] ^ flag[18]) == 65) {
                                          if ((flag[20] - flag[2]) == 32) {
                                            return 1;
                                          }
                                          if ((flag[20] + flag[24]) == 155) {
                                            return 1;
                                          }
                                          if ((flag[20] ^ flag[42]) == 51) {
                                            return 1;
                                          }
                                          if ((flag[20] ^ flag[19]) == 45) {
                                            if ((flag[21] - flag[9]) == 23) {
                                              return 1;
                                            }
                                            if ((flag[21] + flag[23]) == 236) {
                                              return 1;
                                            }
                                            if ((flag[21] - flag[47]) == 8) {
                                              return 1;
                                            }
                                            if ((flag[21] ^ flag[20]) == 47) {
                                              if ((flag[22] + flag[51]) ==
                                                  108) {
                                                return 1;
                                              }
                                              if ((flag[22] + flag[3]) == 121) {
                                                return 1;
                                              }
                                              if ((flag[22] ^ flag[22]) == 8) {
                                                return 1;
                                              }
                                              if ((flag[22] ^ flag[21]) == 64) {
                                                if ((flag[23] + flag[46]) ==
                                                    175) {
                                                  return 1;
                                                }
                                                if ((flag[23] + flag[43]) ==
                                                    237) {
                                                  return 1;
                                                }
                                                if ((flag[23] - flag[17]) ==
                                                    17) {
                                                  return 1;
                                                }
                                                if ((flag[23] + flag[22]) ==
                                                    167) {
                                                  if ((flag[24] + flag[55]) ==
                                                      109) {
                                                    return 1;
                                                  }
                                                  if ((flag[24] ^ flag[62]) ==
                                                      77) {
                                                    return 1;
                                                  }
                                                  if ((flag[24] - flag[44]) ==
                                                      1) {
                                                    return 1;
                                                  }
                                                  if ((flag[24] ^ flag[23]) ==
                                                      68) {
                                                    if ((flag[25] - flag[53]) ==
                                                        -6) {
                                                      return 1;
                                                    }
                                                    if ((flag[25] ^ flag[5]) ==
                                                        79) {
                                                      return 1;
                                                    }
                                                    if ((flag[25] + flag[34]) ==
                                                        166) {
                                                      return 1;
                                                    }
                                                    if ((flag[25] + flag[24]) ==
                                                        165) {
                                                      if ((flag[26] -
                                                           flag[0]) == 39) {
                                                        return 1;
                                                      }
                                                      if ((flag[26] -
                                                           flag[14]) == 8) {
                                                        return 1;
                                                      }
                                                      if ((flag[26] -
                                                           flag[26]) == 9) {
                                                        return 1;
                                                      }
                                                      if ((flag[26] -
                                                           flag[25]) == -12) {
                                                        if ((flag[27] +
                                                             flag[51]) == 175) {
                                                          return 1;
                                                        }
                                                        if ((flag[27] +
                                                             flag[33]) == 224) {
                                                          return 1;
                                                        }
                                                        if ((flag[27] ^
                                                             flag[29]) == 21) {
                                                          return 1;
                                                        }
                                                        if ((flag[27] +
                                                             flag[26]) == 219) {
                                                          if ((flag[28] +
                                                               flag[32]) ==
                                                              161) {
                                                            return 1;
                                                          }
                                                          if ((flag[28] -
                                                               flag[53]) ==
                                                              -69) {
                                                            return 1;
                                                          }
                                                          if ((flag[28] ^
                                                               flag[20]) ==
                                                              85) {
                                                            return 1;
                                                          }
                                                          if ((flag[28] +
                                                               flag[27]) ==
                                                              166) {
                                                            if ((flag[29] ^
                                                                 flag[50]) ==
                                                                47) {
                                                              return 1;
                                                            }
                                                            if ((flag[29] -
                                                                 flag[52]) ==
                                                                -4) {
                                                              return 1;
                                                            }
                                                            if ((flag[29] ^
                                                                 flag[8]) ==
                                                                37) {
                                                              return 1;
                                                            }
                                                            if ((flag[29] +
                                                                 flag[28]) ==
                                                                144) {
                                                              if ((flag[30] ^
                                                                   flag[39]) ==
                                                                  15) {
                                                                return 1;
                                                              }
                                                              if ((flag[30] ^
                                                                   flag[2]) ==
                                                                  113) {
                                                                return 1;
                                                              }
                                                              if ((flag[30] ^
                                                                   flag[35]) ==
                                                                  88) {
                                                                return 1;
                                                              }
                                                              if ((flag[30] -
                                                                   flag[29]) ==
                                                                  -42) {
                                                                if ((flag[31] ^
                                                                     flag[20]) ==
                                                                    29) {
                                                                  return 1;
                                                                }
                                                                if ((flag[31] +
                                                                     flag[55]) ==
                                                                    172) {
                                                                  return 1;
                                                                }
                                                                if ((flag[31] -
                                                                     flag[32]) ==
                                                                    21) {
                                                                  return 1;
                                                                }
                                                                if ((flag[31] -
                                                                     flag[30]) ==
                                                                    68) {
                                                                  if ((flag[32] +
                                                                       flag[55]) ==
                                                                      161) {
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] ^
                                                                       flag[58]) ==
                                                                      85) {
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] +
                                                                       flag[8]) ==
                                                                      230) {
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] -
                                                                       flag[31]) ==
                                                                      -12) {
                                                                    if ((flag[33] -
                                                                         flag[41]) ==
                                                                        54) {
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] +
                                                                         flag[17]) ==
                                                                        217) {
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] -
                                                                         flag[0]) ==
                                                                        35) {
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] -
                                                                         flag[32]) ==
                                                                        -11) {
                                                                      if ((flag[34] -
                                                                           flag[48]) ==
                                                                          -42) {
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] -
                                                                           flag[6]) ==
                                                                          -55) {
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] -
                                                                           flag[22]) ==
                                                                          5) {
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] +
                                                                           flag[33]) ==
                                                                          146) {
                                                                        if ((flag[35] ^
                                                                             flag[61]) ==
                                                                            29) {
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] +
                                                                             flag[25]) ==
                                                                            229) {
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] +
                                                                             flag[43]) ==
                                                                            234) {
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] -
                                                                             flag[34]) ==
                                                                            60) {
                                                                          if ((flag[36] ^
                                                                               flag[24]) ==
                                                                              10) {
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] +
                                                                               flag[26]) ==
                                                                              158) {
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] ^
                                                                               flag[12]) ==
                                                                              84) {
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] -
                                                                               flag[35]) ==
                                                                              -59) {
                                                                            if ((flag[37] ^
                                                                                 flag[40]) ==
                                                                                31) {
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] -
                                                                                 flag[35]) ==
                                                                                -8) {
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] ^
                                                                                 flag[19]) ==
                                                                                22) {
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] -
                                                                                 flag[36]) ==
                                                                                50) {
                                                                              if ((flag[38] +
                                                                                   flag[24]) ==
                                                                                  153) {
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] +
                                                                                   flag[18]) ==
                                                                                  147) {
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] +
                                                                                   flag[19]) ==
                                                                                  210) {
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] ^
                                                                                   flag[37]) ==
                                                                                  60) {
                                                                                if ((flag[39] ^
                                                                                     flag[33]) ==
                                                                                    90) {
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] ^
                                                                                     flag[60]) ==
                                                                                    2) {
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] -
                                                                                     flag[35]) ==
                                                                                    -48) {
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] +
                                                                                     flag[38]) ==
                                                                                    146) {
                                                                                  if ((flag[40] +
                                                                                       flag[60]) ==
                                                                                      175) {
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] +
                                                                                       flag[47]) ==
                                                                                      239) {
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] -
                                                                                       flag[62]) ==
                                                                                      2) {
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] ^
                                                                                       flag[39]) ==
                                                                                      75) {
                                                                                    if ((flag[41] ^
                                                                                         flag[30]) ==
                                                                                        15) {
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] +
                                                                                         flag[59]) ==
                                                                                        101) {
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] +
                                                                                         flag[46]) ==
                                                                                        109) {
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] +
                                                                                         flag[40]) ==
                                                                                        171) {
                                                                                      if ((flag[42] +
                                                                                           flag[40]) ==
                                                                                          222) {
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] -
                                                                                           flag[46]) ==
                                                                                          60) {
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] -
                                                                                           flag[13]) ==
                                                                                          56) {
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] ^
                                                                                           flag[41]) ==
                                                                                          80) {
                                                                                        if ((flag[43] ^
                                                                                             flag[48]) ==
                                                                                            28) {
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] ^
                                                                                             flag[4]) ==
                                                                                            8) {
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] -
                                                                                             flag[48]) ==
                                                                                            26) {
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] -
                                                                                             flag[42]) ==
                                                                                            18) {
                                                                                          if ((flag[44] -
                                                                                               flag[27]) ==
                                                                                              -55) {
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] +
                                                                                               flag[49]) ==
                                                                                              115) {
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] +
                                                                                               flag[31]) ==
                                                                                              178) {
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] ^
                                                                                               flag[43]) ==
                                                                                              66) {
                                                                                            if ((flag[45] -
                                                                                                 flag[10]) ==
                                                                                                4) {
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] -
                                                                                                 flag[43]) ==
                                                                                                -66) {
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] +
                                                                                                 flag[63]) ==
                                                                                                61) {
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] ^
                                                                                                 flag[44]) ==
                                                                                                6) {
                                                                                              if ((flag[46] ^
                                                                                                   flag[31]) ==
                                                                                                  176) {
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] +
                                                                                                   flag[22]) ==
                                                                                                  103) {
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] -
                                                                                                   flag[46]) ==
                                                                                                  7) {
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] ^
                                                                                                   flag[45]) ==
                                                                                                  1) {
                                                                                                if ((flag[47] ^
                                                                                                     flag[49]) ==
                                                                                                    86) {
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] -
                                                                                                     flag[5]) ==
                                                                                                    68) {
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] +
                                                                                                     flag[43]) ==
                                                                                                    237) {
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] +
                                                                                                     flag[46]) ==
                                                                                                    158) {
                                                                                                  if ((flag[48] ^
                                                                                                       flag[35]) ==
                                                                                                      48) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] -
                                                                                                       flag[48]) ==
                                                                                                      1) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] +
                                                                                                       flag[11]) ==
                                                                                                      155) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] ^
                                                                                                       flag[47]) ==
                                                                                                      49) {
                                                                                                    if ((flag[49] +
                                                                                                         flag[23]) ==
                                                                                                        178) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] +
                                                                                                         flag[19]) ==
                                                                                                        167) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] -
                                                                                                         flag[28]) ==
                                                                                                        6) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] ^
                                                                                                         flag[48]) ==
                                                                                                        107) {
                                                                                                      if ((flag[50] +
                                                                                                           flag[9]) ==
                                                                                                          206) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] -
                                                                                                           flag[8]) ==
                                                                                                          4) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] -
                                                                                                           flag[22]) ==
                                                                                                          72) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] -
                                                                                                           flag[49]) ==
                                                                                                          58) {
                                                                                                        if ((flag[51] ^
                                                                                                             flag[60]) ==
                                                                                                            13) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] ^
                                                                                                             flag[17]) ==
                                                                                                            66) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] ^
                                                                                                             flag[12]) ==
                                                                                                            85) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] -
                                                                                                             flag[50]) ==
                                                                                                            -58) {
                                                                                                          if ((flag[52] +
                                                                                                               flag[28]) ==
                                                                                                              164) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] -
                                                                                                               flag[11]) ==
                                                                                                              57) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] ^
                                                                                                               flag[45]) ==
                                                                                                              95) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] +
                                                                                                               flag[51]) ==
                                                                                                              160) {
                                                                                                            if ((flag[53] -
                                                                                                                 flag[19]) ==
                                                                                                                17) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] ^
                                                                                                                 flag[20]) ==
                                                                                                                26) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] -
                                                                                                                 flag[27]) ==
                                                                                                                6) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] -
                                                                                                                 flag[52]) ==
                                                                                                                13) {
                                                                                                              if ((flag[54] ^
                                                                                                                   flag[62]) ==
                                                                                                                  178) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] ^
                                                                                                                   flag[5]) ==
                                                                                                                  0) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] ^
                                                                                                                   flag[18]) ==
                                                                                                                  2) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] ^
                                                                                                                   flag[53]) ==
                                                                                                                  76) {
                                                                                                                if ((flag[55] +
                                                                                                                     flag[60]) ==
                                                                                                                    106) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] +
                                                                                                                     flag[39]) ==
                                                                                                                    110) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] -
                                                                                                                     flag[4]) ==
                                                                                                                    -70) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] -
                                                                                                                     flag[54]) ==
                                                                                                                    -4) {
                                                                                                                  if ((flag[56] -
                                                                                                                       flag[51]) ==
                                                                                                                      11) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] ^
                                                                                                                       flag[2]) ==
                                                                                                                      125) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] -
                                                                                                                       flag[46]) ==
                                                                                                                      8) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] +
                                                                                                                       flag[55]) ==
                                                                                                                      102) {
                                                                                                                    if ((flag[57] ^
                                                                                                                         flag[47]) ==
                                                                                                                        39) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] -
                                                                                                                         flag[60]) ==
                                                                                                                        54) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] +
                                                                                                                         flag[52]) ==
                                                                                                                        211) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] +
                                                                                                                         flag[56]) ==
                                                                                                                        148) {
                                                                                                                      if ((flag[58] ^
                                                                                                                           flag[18]) ==
                                                                                                                          10) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] -
                                                                                                                           flag[9]) ==
                                                                                                                          -38) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] +
                                                                                                                           flag[17]) ==
                                                                                                                          169) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] -
                                                                                                                           flag[57]) ==
                                                                                                                          -40) {
                                                                                                                        if ((flag[59] -
                                                                                                                             flag[42]) ==
                                                                                                                            -41) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] +
                                                                                                                             flag[60]) ==
                                                                                                                            102) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] ^
                                                                                                                             flag[47]) ==
                                                                                                                            72) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] -
                                                                                                                             flag[58]) ==
                                                                                                                            -7) {
                                                                                                                          if ((flag[60] ^
                                                                                                                               flag[17]) ==
                                                                                                                              74) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] +
                                                                                                                               flag[51]) ==
                                                                                                                              101) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] ^
                                                                                                                               flag[14]) ==
                                                                                                                              89) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] ^
                                                                                                                               flag[59]) ==
                                                                                                                              0) {
                                                                                                                            if ((flag[61] -
                                                                                                                                 flag[63]) ==
                                                                                                                                106) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] +
                                                                                                                                 flag[26]) ==
                                                                                                                                214) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] ^
                                                                                                                                 flag[21]) ==
                                                                                                                                25) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] +
                                                                                                                                 flag[60]) ==
                                                                                                                                156) {
                                                                                                                              if ((flag[62] -
                                                                                                                                   flag[5]) ==
                                                                                                                                  80) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] +
                                                                                                                                   flag[25]) ==
                                                                                                                                  247) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] +
                                                                                                                                   flag[49]) ==
                                                                                                                                  186) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] -
                                                                                                                                   flag[61]) ==
                                                                                                                                  17) {
                                                                                                                                if ((flag[63] ^
                                                                                                                                     flag[43]) ==
                                                                                                                                    117) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                if ((flag[63] +
                                                                                                                                     flag[16]) ==
                                                                                                                                    133) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                if ((flag[63] +
                                                                                                                                     flag[6]) ==
                                                                                                                                    128) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                if ((flag[63] +
                                                                                                                                     flag[62]) ==
                                                                                                                                    135) {
                                                                                                                                  return 0;
                                                                                                                                }
                                                                                                                                if ((flag[63] -
                                                                                                                                     flag[9]) ==
                                                                                                                                    -79) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                if ((flag[63] ^
                                                                                                                                     flag[33]) ==
                                                                                                                                    110) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                if ((flag[63] -
                                                                                                                                     flag[38]) ==
                                                                                                                                    -82) {
                                                                                                                                  return 1;
                                                                                                                                }
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] ^
                                                                                                                                   flag[19]) ==
                                                                                                                                  6) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] ^
                                                                                                                                   flag[54]) ==
                                                                                                                                  74) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              if ((flag[62] +
                                                                                                                                   flag[59]) ==
                                                                                                                                  177) {
                                                                                                                                return 1;
                                                                                                                              }
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] -
                                                                                                                                 flag[14]) ==
                                                                                                                                22) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] ^
                                                                                                                                 flag[53]) ==
                                                                                                                                19) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            if ((flag[61] ^
                                                                                                                                 flag[54]) ==
                                                                                                                                82) {
                                                                                                                              return 1;
                                                                                                                            }
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] +
                                                                                                                               flag[27]) ==
                                                                                                                              169) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] -
                                                                                                                               flag[59]) ==
                                                                                                                              5) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          if ((flag[60] -
                                                                                                                               flag[52]) ==
                                                                                                                              -55) {
                                                                                                                            return 1;
                                                                                                                          }
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] ^
                                                                                                                             flag[7]) ==
                                                                                                                            11) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] ^
                                                                                                                             flag[1]) ==
                                                                                                                            100) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        if ((flag[59] ^
                                                                                                                             flag[44]) ==
                                                                                                                            15) {
                                                                                                                          return 1;
                                                                                                                        }
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] +
                                                                                                                           flag[41]) ==
                                                                                                                          112) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] -
                                                                                                                           flag[21]) ==
                                                                                                                          -47) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      if ((flag[58] ^
                                                                                                                           flag[50]) ==
                                                                                                                          69) {
                                                                                                                        return 1;
                                                                                                                      }
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] ^
                                                                                                                         flag[37]) ==
                                                                                                                        51) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] +
                                                                                                                         flag[48]) ==
                                                                                                                        198) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    if ((flag[57] +
                                                                                                                         flag[56]) ==
                                                                                                                        158) {
                                                                                                                      return 1;
                                                                                                                    }
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] +
                                                                                                                       flag[32]) ==
                                                                                                                      163) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] ^
                                                                                                                       flag[6]) ==
                                                                                                                      64) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  if ((flag[56] +
                                                                                                                       flag[38]) ==
                                                                                                                      155) {
                                                                                                                    return 1;
                                                                                                                  }
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] -
                                                                                                                     flag[44]) ==
                                                                                                                    1) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] +
                                                                                                                     flag[12]) ==
                                                                                                                    148) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                if ((flag[55] ^
                                                                                                                     flag[41]) ==
                                                                                                                    13) {
                                                                                                                  return 1;
                                                                                                                }
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] ^
                                                                                                                   flag[53]) ==
                                                                                                                  78) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] -
                                                                                                                   flag[34]) ==
                                                                                                                  13) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              if ((flag[54] -
                                                                                                                   flag[58]) ==
                                                                                                                  0) {
                                                                                                                return 1;
                                                                                                              }
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] -
                                                                                                                 flag[14]) ==
                                                                                                                29) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] +
                                                                                                                 flag[30]) ==
                                                                                                                180) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            if ((flag[53] -
                                                                                                                 flag[11]) ==
                                                                                                                73) {
                                                                                                              return 1;
                                                                                                            }
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] +
                                                                                                               flag[38]) ==
                                                                                                              205) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] +
                                                                                                               flag[55]) ==
                                                                                                              163) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          if ((flag[52] +
                                                                                                               flag[27]) ==
                                                                                                              230) {
                                                                                                            return 1;
                                                                                                          }
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] ^
                                                                                                             flag[1]) ==
                                                                                                            96) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] ^
                                                                                                             flag[53]) ==
                                                                                                            180) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        if ((flag[51] -
                                                                                                             flag[32]) ==
                                                                                                            -50) {
                                                                                                          return 1;
                                                                                                        }
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] -
                                                                                                           flag[11]) ==
                                                                                                          61) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] +
                                                                                                           flag[3]) ==
                                                                                                          186) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      if ((flag[50] ^
                                                                                                           flag[40]) ==
                                                                                                          17) {
                                                                                                        return 1;
                                                                                                      }
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] ^
                                                                                                         flag[10]) ==
                                                                                                        14) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] +
                                                                                                         flag[35]) ==
                                                                                                        162) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    if ((flag[49] +
                                                                                                         flag[7]) ==
                                                                                                        109) {
                                                                                                      return 1;
                                                                                                    }
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] +
                                                                                                       flag[45]) ==
                                                                                                      153) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] +
                                                                                                       flag[49]) ==
                                                                                                      152) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  if ((flag[48] +
                                                                                                       flag[19]) ==
                                                                                                      216) {
                                                                                                    return 1;
                                                                                                  }
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] +
                                                                                                     flag[38]) ==
                                                                                                    209) {
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] ^
                                                                                                     flag[9]) ==
                                                                                                    13) {
                                                                                                  return 1;
                                                                                                }
                                                                                                if ((flag[47] -
                                                                                                     flag[47]) ==
                                                                                                    1) {
                                                                                                  return 1;
                                                                                                }
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] ^
                                                                                                   flag[32]) ==
                                                                                                  64) {
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] +
                                                                                                   flag[13]) ==
                                                                                                  108) {
                                                                                                return 1;
                                                                                              }
                                                                                              if ((flag[46] ^
                                                                                                   flag[47]) ==
                                                                                                  69) {
                                                                                                return 1;
                                                                                              }
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] ^
                                                                                                 flag[26]) ==
                                                                                                94) {
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] +
                                                                                                 flag[29]) ==
                                                                                                149) {
                                                                                              return 1;
                                                                                            }
                                                                                            if ((flag[45] -
                                                                                                 flag[58]) ==
                                                                                                1) {
                                                                                              return 1;
                                                                                            }
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] ^
                                                                                               flag[14]) ==
                                                                                              80) {
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] ^
                                                                                               flag[22]) ==
                                                                                              5) {
                                                                                            return 1;
                                                                                          }
                                                                                          if ((flag[44] +
                                                                                               flag[48]) ==
                                                                                              157) {
                                                                                            return 1;
                                                                                          }
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] +
                                                                                             flag[55]) ==
                                                                                            172) {
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] +
                                                                                             flag[17]) ==
                                                                                            237) {
                                                                                          return 1;
                                                                                        }
                                                                                        if ((flag[43] -
                                                                                             flag[45]) ==
                                                                                            77) {
                                                                                          return 1;
                                                                                        }
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] ^
                                                                                           flag[2]) ==
                                                                                          43) {
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] ^
                                                                                           flag[63]) ==
                                                                                          110) {
                                                                                        return 1;
                                                                                      }
                                                                                      if ((flag[42] -
                                                                                           flag[39]) ==
                                                                                          54) {
                                                                                        return 1;
                                                                                      }
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] +
                                                                                         flag[56]) ==
                                                                                        108) {
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] +
                                                                                         flag[39]) ==
                                                                                        105) {
                                                                                      return 1;
                                                                                    }
                                                                                    if ((flag[41] -
                                                                                         flag[16]) ==
                                                                                        -61) {
                                                                                      return 1;
                                                                                    }
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] ^
                                                                                       flag[46]) ==
                                                                                      77) {
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] ^
                                                                                       flag[55]) ==
                                                                                      67) {
                                                                                    return 1;
                                                                                  }
                                                                                  if ((flag[40] ^
                                                                                       flag[18]) ==
                                                                                      66) {
                                                                                    return 1;
                                                                                  }
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] ^
                                                                                     flag[18]) ==
                                                                                    11) {
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] +
                                                                                     flag[52]) ==
                                                                                    167) {
                                                                                  return 1;
                                                                                }
                                                                                if ((flag[39] +
                                                                                     flag[42]) ==
                                                                                    152) {
                                                                                  return 1;
                                                                                }
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] -
                                                                                   flag[34]) ==
                                                                                  56) {
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] -
                                                                                   flag[31]) ==
                                                                                  -25) {
                                                                                return 1;
                                                                              }
                                                                              if ((flag[38] -
                                                                                   flag[43]) ==
                                                                                  -20) {
                                                                                return 1;
                                                                              }
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] -
                                                                                 flag[37]) ==
                                                                                4) {
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] +
                                                                                 flag[6]) ==
                                                                                217) {
                                                                              return 1;
                                                                            }
                                                                            if ((flag[37] ^
                                                                                 flag[31]) ==
                                                                                225) {
                                                                              return 1;
                                                                            }
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] +
                                                                               flag[21]) ==
                                                                              162) {
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] -
                                                                               flag[26]) ==
                                                                              -46) {
                                                                            return 1;
                                                                          }
                                                                          if ((flag[36] +
                                                                               flag[9]) ==
                                                                              154) {
                                                                            return 1;
                                                                          }
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] ^
                                                                             flag[43]) ==
                                                                            23) {
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] ^
                                                                             flag[54]) ==
                                                                            80) {
                                                                          return 1;
                                                                        }
                                                                        if ((flag[35] -
                                                                             flag[48]) ==
                                                                            23) {
                                                                          return 1;
                                                                        }
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] -
                                                                           flag[48]) ==
                                                                          -38) {
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] ^
                                                                           flag[59]) ==
                                                                          3) {
                                                                        return 1;
                                                                      }
                                                                      if ((flag[34] ^
                                                                           flag[25]) ==
                                                                          72) {
                                                                        return 1;
                                                                      }
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] +
                                                                         flag[17]) ==
                                                                        220) {
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] +
                                                                         flag[21]) ==
                                                                        215) {
                                                                      return 1;
                                                                    }
                                                                    if ((flag[33] +
                                                                         flag[23]) ==
                                                                        224) {
                                                                      return 1;
                                                                    }
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] ^
                                                                       flag[49]) ==
                                                                      83) {
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] +
                                                                       flag[23]) ==
                                                                      234) {
                                                                    return 1;
                                                                  }
                                                                  if ((flag[32] ^
                                                                       flag[13]) ==
                                                                      85) {
                                                                    return 1;
                                                                  }
                                                                  return 1;
                                                                }
                                                                if ((flag[31] ^
                                                                     flag[50]) ==
                                                                    14) {
                                                                  return 1;
                                                                }
                                                                if ((flag[31] +
                                                                     flag[40]) ==
                                                                    248) {
                                                                  return 1;
                                                                }
                                                                if ((flag[31] +
                                                                     flag[33]) ==
                                                                    225) {
                                                                  return 1;
                                                                }
                                                                return 1;
                                                              }
                                                              if ((flag[30] +
                                                                   flag[39]) ==
                                                                  105) {
                                                                return 1;
                                                              }
                                                              if ((flag[30] ^
                                                                   flag[8]) ==
                                                                  64) {
                                                                return 1;
                                                              }
                                                              if ((flag[30] -
                                                                   flag[37]) ==
                                                                  -41) {
                                                                return 1;
                                                              }
                                                              return 1;
                                                            }
                                                            if ((flag[29] ^
                                                                 flag[21]) ==
                                                                41) {
                                                              return 1;
                                                            }
                                                            if ((flag[29] +
                                                                 flag[35]) ==
                                                                212) {
                                                              return 1;
                                                            }
                                                            if ((flag[29] -
                                                                 flag[11]) ==
                                                                49) {
                                                              return 1;
                                                            }
                                                            return 1;
                                                          }
                                                          if ((flag[28] ^
                                                               flag[22]) == 8) {
                                                            return 1;
                                                          }
                                                          if ((flag[28] ^
                                                               flag[22]) == 9) {
                                                            return 1;
                                                          }
                                                          if ((flag[28] +
                                                               flag[44]) ==
                                                              113) {
                                                            return 1;
                                                          }
                                                          return 1;
                                                        }
                                                        if ((flag[27] -
                                                             flag[61]) == 14) {
                                                          return 1;
                                                        }
                                                        if ((flag[27] +
                                                             flag[2]) == 191) {
                                                          return 1;
                                                        }
                                                        if ((flag[27] +
                                                             flag[62]) == 252) {
                                                          return 1;
                                                        }
                                                        return 1;
                                                      }
                                                      if ((flag[26] ^
                                                           flag[60]) == 83) {
                                                        return 1;
                                                      }
                                                      if ((flag[26] -
                                                           flag[51]) == 52) {
                                                        return 1;
                                                      }
                                                      if ((flag[26] -
                                                           flag[36]) == 55) {
                                                        return 1;
                                                      }
                                                      return 1;
                                                    }
                                                    if ((flag[25] ^ flag[1]) ==
                                                        35) {
                                                      return 1;
                                                    }
                                                    if ((flag[25] ^ flag[4]) ==
                                                        12) {
                                                      return 1;
                                                    }
                                                    if ((flag[25] ^ flag[31]) ==
                                                        9) {
                                                      return 1;
                                                    }
                                                    return 1;
                                                  }
                                                  if ((flag[24] ^ flag[7]) ==
                                                      9) {
                                                    return 1;
                                                  }
                                                  if ((flag[24] ^ flag[18]) ==
                                                      4) {
                                                    return 1;
                                                  }
                                                  if ((flag[24] - flag[20]) ==
                                                      -43) {
                                                    return 1;
                                                  }
                                                  return 1;
                                                }
                                                if ((flag[23] - flag[29]) ==
                                                    34) {
                                                  return 1;
                                                }
                                                if ((flag[23] ^ flag[37]) ==
                                                    30) {
                                                  return 1;
                                                }
                                                if ((flag[23] ^ flag[23]) ==
                                                    11) {
                                                  return 1;
                                                }
                                                return 1;
                                              }
                                              if ((flag[22] + flag[17]) ==
                                                  165) {
                                                return 1;
                                              }
                                              if ((flag[22] + flag[49]) ==
                                                  101) {
                                                return 1;
                                              }
                                              if ((flag[22] + flag[23]) ==
                                                  173) {
                                                return 1;
                                              }
                                              return 1;
                                            }
                                            if ((flag[21] - flag[18]) == 68) {
                                              return 1;
                                            }
                                            if ((flag[21] + flag[30]) == 173) {
                                              return 1;
                                            }
                                            if ((flag[21] - flag[29]) == 18) {
                                              return 1;
                                            }
                                            return 1;
                                          }
                                          if ((flag[20] - flag[30]) == 52) {
                                            return 1;
                                          }
                                          if ((flag[20] + flag[9]) == 191) {
                                            return 1;
                                          }
                                          if ((flag[20] ^ flag[45]) == 106) {
                                            return 1;
                                          }
                                          return 1;
                                        }
                                        if ((flag[19] - flag[5]) == 66) {
                                          return 1;
                                        }
                                        if ((flag[19] - flag[28]) == 72) {
                                          return 1;
                                        }
                                        if ((flag[19] ^ flag[15]) == 74) {
                                          return 1;
                                        }
                                        return 1;
                                      }
                                      if ((flag[18] ^ flag[6]) == 92) {
                                        return 1;
                                      }
                                      if ((flag[18] - flag[35]) == -49) {
                                        return 1;
                                      }
                                      if ((flag[18] + flag[13]) == 110) {
                                        return 1;
                                      }
                                      return 1;
                                    }
                                    if ((flag[17] - flag[60]) == 65) {
                                      return 1;
                                    }
                                    if ((flag[17] - flag[7]) == 63) {
                                      return 1;
                                    }
                                    if ((flag[17] + flag[23]) == 234) {
                                      return 1;
                                    }
                                    return 1;
                                  }
                                  if ((flag[16] + flag[1]) == 197) {
                                    return 1;
                                  }
                                  if ((flag[16] + flag[21]) == 235) {
                                    return 1;
                                  }
                                  if ((flag[16] - flag[30]) == 65) {
                                    return 1;
                                  }
                                  return 1;
                                }
                                if ((flag[15] + flag[41]) == 105) {
                                  return 1;
                                }
                                if ((flag[15] + flag[23]) == 181) {
                                  return 1;
                                }
                                if ((flag[15] - flag[51]) == 3) {
                                  return 1;
                                }
                                return 1;
                              }
                              if ((flag[14] - flag[49]) == 52) {
                                return 1;
                              }
                              if ((flag[14] + flag[61]) == 204) {
                                return 1;
                              }
                              if ((flag[14] + flag[23]) == 216) {
                                return 1;
                              }
                              return 1;
                            }
                            if ((flag[13] ^ flag[58]) == 13) {
                              return 1;
                            }
                            if ((flag[13] - flag[50]) == -55) {
                              return 1;
                            }
                            if ((flag[13] - flag[35]) == -55) {
                              return 1;
                            }
                            return 1;
                          }
                          if ((flag[12] + flag[50]) == 207) {
                            return 1;
                          }
                          if ((flag[12] + flag[39]) == 149) {
                            return 1;
                          }
                          if ((flag[12] - flag[14]) == 4) {
                            return 1;
                          }
                          return 1;
                        }
                        if ((flag[11] - flag[35]) == -45) {
                          return 1;
                        }
                        if ((flag[11] - flag[22]) == 10) {
                          return 1;
                        }
                        if ((flag[11] - flag[21]) == -50) {
                          return 1;
                        }
                        return 1;
                      }
                      if ((flag[10] - flag[61]) == -51) {
                        return 1;
                      }
                      if ((flag[10] ^ flag[49]) == 12) {
                        return 1;
                      }
                      if ((flag[10] ^ flag[33]) == 90) {
                        return 1;
                      }
                      return 1;
                    }
                    if ((flag[9] - flag[11]) == 50) {
                      return 1;
                    }
                    if ((flag[9] ^ flag[26]) == 51) {
                      return 1;
                    }
                    if ((flag[9] - flag[43]) == -19) {
                      return 1;
                    }
                    return 1;
                  }
                  if ((flag[8] + flag[53]) == 244) {
                    return 1;
                  }
                  if ((flag[8] + flag[63]) == 134) {
                    return 1;
                  }
                  if ((flag[8] - flag[42]) == 21) {
                    return 1;
                  }
                  return 1;
                }
                if ((flag[7] + flag[11]) == 110) {
                  return 1;
                }
                if ((flag[7] + flag[5]) == 114) {
                  return 1;
                }
                if ((flag[7] ^ flag[59]) == 0) {
                  return 1;
                }
                return 1;
              }
              if ((flag[6] ^ flag[56]) == 88) {
                return 1;
              }
              if ((flag[6] - flag[42]) == 17) {
                return 1;
              }
              if ((flag[6] + flag[16]) == 235) {
                return 1;
              }
              return 1;
            }
            if ((flag[5] ^ flag[28]) == 15) {
              return 1;
            }
            if ((flag[5] - flag[23]) == -65) {
              return 1;
            }
            if ((flag[5] ^ flag[28]) == 14) {
              return 1;
            }
            return 1;
          }
          if ((flag[4] ^ flag[42]) == 17) {
            return 1;
          }
          if ((flag[4] ^ flag[24]) == 65) {
            return 1;
          }
          if ((flag[4] - flag[5]) == 79) {
            return 1;
          }
          return 1;
        }
        if ((flag[3] + flag[12]) == 171) {
          return 1;
        }
        if ((flag[3] - flag[17]) == -38) {
          return 1;
        }
        if ((flag[3] - flag[29]) == -17) {
          return 1;
        }
        return 1;
      }
      if ((flag[2] + flag[50]) == 184) {
        return 1;
      }
      if ((flag[2] ^ flag[31]) == 192) {
        return 1;
      }
      if ((flag[2] + flag[6]) == 183) {
        return 1;
      }
      return 1;
    }
    if ((flag[1] ^ flag[13]) == 116) {
      return 1;
    }
    if ((flag[1] - flag[28]) == 29) {
      return 1;
    }
    if ((flag[1] - flag[10]) == 31) {
      return 1;
    }
    return 1;
  }
  if ((flag[0] + flag[54]) == 125) {
    return 1;
  }
  if ((flag[0] + flag[55]) == 122) {
    return 1;
  }
  if ((flag[0] + flag[16]) == 195) {
    return 1;
  }
  return 1;
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    puts("Failed to execute. Usage: ./licence <key file name>");
    return 1;
  }

  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    puts("Failed to open file");
    return 1;
  }

  /* ライセンスファイル1行目 */

  char begin[29];
  if (fgets(begin, 29, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (strcmp(begin, "-----BEGIN LICENCE KEY-----\n") != 0) {
    puts("Failed to activate.");
    return 1;
  }

  /* ライセンスファイル2行目 */
  char flag[65];
  if (fgets(flag, 65, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (check(flag)) {
    puts("Failed to activate.");
    return 1;
  }

  /* ライセンスファイル3行目 */
  char end[27];
  if (fgets(end, 27, fp) == NULL) {
    puts("Failed to read file");
    return 1;
  }

  if (strcmp(end, "-----END LICENCE KEY-----\n") != 0) {
    puts("Failed to activate.");
    return 1;
  }

  fclose(fp);

  puts("Correct! This software is successfully activated!");
  return 0;
}
