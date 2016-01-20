(define (problem robots-01)
   (:domain robots)
   (:objects
              x111 x112 x113 x114 x115 x116
              x121 x122 x123 x124 x125 x126
              x131 x132 x133 x134 x135 x136
              x141 x142 x143 x144 x145 x146
              x151 x152 x153 x154 x155 x156
              x161 x162 x163 x164 x165 x166

              x211 x212 x213 x214 x215 x216
              x221 x222 x223 x224 x225 x226
              x231 x232 x233 x234 x235 x236
              x241 x242 x243 x244 x245 x246
              x251 x252 x253 x254 x255 x256
              x261 x262 x263 x264 x265 x266

              x311 x312 x313 x314 x315 x316
              x321 x322 x323 x324 x325 x326
              x331 x332 x333 x334 x335 x336
              x341 x342 x343 x344 x345 x346
              x351 x352 x353 x354 x355 x356
              x361 x362 x363 x364 x365 x366 - intersection)
   (:init
     (at robot x166)

; Level 1 X Axis Paths

     (adjoin x111 x112)
     (adjoin x112 x113)
     (adjoin x113 x114)
     (adjoin x114 x115)
     (adjoin x115 x116)

     (adjoin x121 x122)
     (adjoin x122 x123)
     (adjoin x123 x124)
     (adjoin x124 x125)
     (adjoin x125 x126)

     (adjoin x131 x132)
     (adjoin x132 x133)
     (adjoin x133 x134)
     (adjoin x134 x135)
     (adjoin x135 x136)

     (adjoin x141 x142)
     (adjoin x142 x143)
     (adjoin x143 x144)
     (adjoin x144 x145)
     (adjoin x145 x146)

     (adjoin x151 x152)
     (adjoin x152 x153)
     (adjoin x153 x154)
     (adjoin x154 x155)
     (adjoin x155 x156)

     (adjoin x161 x162)
     (adjoin x162 x163)
     (adjoin x163 x164)
     (adjoin x164 x165)
     (adjoin x165 x166)

; Level 1 Y Axis Paths

     (adjoin x111 x121)
     (adjoin x121 x131)
     (adjoin x131 x141)
     (adjoin x141 x151)
     (adjoin x151 x161)

     (adjoin x112 x122)
     (adjoin x122 x132)
     (adjoin x132 x142)
     (adjoin x142 x152)
     (adjoin x152 x162)

     (adjoin x113 x123)
     (adjoin x123 x133)
     (adjoin x133 x143)
     (adjoin x143 x153)
     (adjoin x153 x163)

     (adjoin x114 x124)
     (adjoin x124 x134)
     (adjoin x134 x144)
     (adjoin x144 x154)
     (adjoin x154 x164)

     (adjoin x115 x125)
     (adjoin x125 x135)
     (adjoin x135 x145)
     (adjoin x145 x155)
     (adjoin x155 x165)

     (adjoin x116 x126)
     (adjoin x126 x136)
     (adjoin x136 x146)
     (adjoin x146 x156)
     (adjoin x156 x166)

; Level 1-2 Z Axis Paths

     (adjoin x111 x211)
     (adjoin x112 x212)
     (adjoin x113 x213)
     (adjoin x114 x214)
     (adjoin x115 x215)
     (adjoin x115 x216)

     (adjoin x121 x221)
     (adjoin x122 x222)
     (adjoin x123 x223)
     (adjoin x124 x224)
     (adjoin x125 x225)
     (adjoin x126 x226)

     (adjoin x131 x231)
     (adjoin x132 x232)
     (adjoin x133 x233)
     (adjoin x134 x234)
     (adjoin x135 x235)
     (adjoin x136 x236)

     (adjoin x141 x241)
     (adjoin x142 x242)
     (adjoin x143 x243)
     (adjoin x144 x244)
     (adjoin x145 x245)
     (adjoin x146 x246)

     (adjoin x151 x251)
     (adjoin x152 x252)
     (adjoin x153 x253)
     (adjoin x154 x254)
     (adjoin x155 x255)
     (adjoin x156 x256)

     (adjoin x161 x261)
     (adjoin x162 x262)
     (adjoin x163 x263)
     (adjoin x164 x264)
     (adjoin x165 x265)
     (adjoin x166 x266)

; Level 2 X Axis Paths

     (adjoin x211 x212)
     (adjoin x212 x213)
     (adjoin x213 x214)
     (adjoin x214 x215)
     (adjoin x215 x216)

     (adjoin x221 x222)
     (adjoin x222 x223)
     (adjoin x223 x224)
     (adjoin x224 x225)
     (adjoin x225 x226)

     (adjoin x231 x232)
     (adjoin x232 x233)
     (adjoin x233 x234)
     (adjoin x234 x235)
     (adjoin x235 x236)

     (adjoin x241 x242)
     (adjoin x242 x243)
     (adjoin x243 x244)
     (adjoin x244 x245)
     (adjoin x245 x246)

     (adjoin x251 x252)
     (adjoin x252 x253)
     (adjoin x253 x254)
     (adjoin x254 x255)
     (adjoin x255 x256)

     (adjoin x261 x262)
     (adjoin x262 x263)
     (adjoin x263 x264)
     (adjoin x264 x265)
     (adjoin x265 x266)

; Level 2 Y Axis Paths

     (adjoin x211 x221)
     (adjoin x221 x231)
     (adjoin x231 x241)
     (adjoin x241 x251)
     (adjoin x251 x261)

     (adjoin x212 x222)
     (adjoin x222 x232)
     (adjoin x232 x242)
     (adjoin x242 x252)
     (adjoin x252 x262)

     (adjoin x213 x223)
     (adjoin x223 x233)
     (adjoin x233 x243)
     (adjoin x243 x253)
     (adjoin x253 x263)

     (adjoin x214 x224)
     (adjoin x224 x234)
     (adjoin x234 x244)
     (adjoin x244 x254)
     (adjoin x254 x264)

     (adjoin x215 x225)
     (adjoin x225 x235)
     (adjoin x235 x245)
     (adjoin x245 x255)
     (adjoin x255 x265)

     (adjoin x216 x226)
     (adjoin x226 x236)
     (adjoin x236 x246)
     (adjoin x246 x256)
     (adjoin x256 x266)

; Level 2-3 Z Axis Paths

     (adjoin x211 x311)
     (adjoin x212 x312)
     (adjoin x213 x313)
     (adjoin x214 x314)
     (adjoin x215 x315)
     (adjoin x216 x316)

     (adjoin x221 x321)
     (adjoin x222 x322)
     (adjoin x223 x323)
     (adjoin x224 x324)
     (adjoin x225 x325)
     (adjoin x226 x326)

     (adjoin x231 x331)
     (adjoin x232 x332)
     (adjoin x233 x333)
     (adjoin x234 x334)
     (adjoin x235 x335)
     (adjoin x236 x336)

     (adjoin x241 x341)
     (adjoin x242 x342)
     (adjoin x243 x343)
     (adjoin x244 x344)
     (adjoin x245 x345)
     (adjoin x246 x346)

     (adjoin x251 x351)
     (adjoin x252 x352)
     (adjoin x253 x353)
     (adjoin x254 x354)
     (adjoin x255 x355)
     (adjoin x256 x356)

     (adjoin x261 x361)
     (adjoin x262 x362)
     (adjoin x263 x363)
     (adjoin x264 x364)
     (adjoin x265 x365)
     (adjoin x266 x366)

; Level 3 X Axis Paths

     (adjoin x311 x312)
     (adjoin x312 x313)
     (adjoin x313 x314)
     (adjoin x314 x315)
     (adjoin x315 x316)

     (adjoin x321 x322)
     (adjoin x322 x323)
     (adjoin x323 x324)
     (adjoin x324 x325)
     (adjoin x325 x326)

     (adjoin x331 x332)
     (adjoin x332 x333)
     (adjoin x333 x334)
     (adjoin x334 x335)
     (adjoin x335 x336)

     (adjoin x341 x342)
     (adjoin x342 x343)
     (adjoin x343 x344)
     (adjoin x344 x345)
     (adjoin x345 x346)

     (adjoin x351 x352)
     (adjoin x352 x353)
     (adjoin x353 x354)
     (adjoin x354 x355)
     (adjoin x355 x356)

     (adjoin x361 x362)
     (adjoin x362 x363)
     (adjoin x363 x364)
     (adjoin x364 x365)
     (adjoin x365 x366)

; Level 3 Y Axis Paths

     (adjoin x311 x321)
     (adjoin x321 x331)
     (adjoin x331 x341)
     (adjoin x341 x351)
     (adjoin x351 x361)

     (adjoin x312 x322)
     (adjoin x322 x332)
     (adjoin x332 x342)
     (adjoin x342 x352)
     (adjoin x352 x362)

     (adjoin x313 x323)
     (adjoin x323 x333)
     (adjoin x333 x343)
     (adjoin x343 x353)
     (adjoin x353 x363)

     (adjoin x314 x324)
     (adjoin x324 x334)
     (adjoin x334 x344)
     (adjoin x344 x354)
     (adjoin x354 x364)

     (adjoin x315 x325)
     (adjoin x325 x335)
     (adjoin x335 x345)
     (adjoin x345 x355)
     (adjoin x355 x365)

     (adjoin x316 x326)
     (adjoin x326 x336)
     (adjoin x336 x346)
     (adjoin x346 x356)
     (adjoin x356 x366)




; Static Blockages

; Level 1 X Blockages

     (blocked x111 x112)
     (blocked x112 x113)
     (blocked x113 x114)
     (blocked x114 x115)
     (blocked x115 x116)

     (blocked x123 x124)
     (blocked x124 x125)

     (blocked x131 x132)
     (blocked x132 x133)
     (blocked x135 x136)

     (blocked x142 x143)
     (blocked x143 x144)

     (blocked x151 x152)
     (blocked x153 x154)
     (blocked x154 x155)

     (blocked x161 x162)
     (blocked x162 x163)
     (blocked x164 x165)

; Level 1 Y Blockages

     (blocked x111 x121)
     (blocked x141 x151)
     (blocked x151 x161)

     (blocked x112 x122)
     (blocked x122 x132)
     (blocked x132 x142)
     (blocked x152 x162)

     (blocked x113 x123)
     (blocked x123 x133)
     (blocked x153 x163)

     (blocked x114 x124)
     (blocked x124 x134)
     (blocked x134 x144)

     (blocked x115 x125)
     (blocked x125 x135)
     (blocked x135 x145)
     (blocked x145 x155)
     (blocked x155 x165)

     (blocked x116 x126)
     (blocked x136 x146)
     (blocked x156 x166)

; Level 1-2 Z Blockages

     (blocked x111 x211)
     (blocked x112 x212)
     (blocked x113 x213)
     (blocked x114 x214)
     (blocked x115 x215)
     (blocked x116 x216)

     (blocked x121 x221)
     (blocked x122 x222)
     (blocked x124 x224)
     (blocked x126 x226)

     (blocked x131 x231)
     (blocked x132 x232)
     (blocked x133 x233)
     (blocked x134 x234)

     (blocked x141 x241)
     (blocked x142 x242)
     (blocked x143 x243)
     (blocked x144 x244)
     (blocked x145 x245)
     (blocked x146 x246)

     (blocked x151 x251)
     (blocked x152 x252)
     (blocked x153 x253)
     (blocked x154 x254)
     (blocked x156 x256)

     (blocked x161 x261)
     (blocked x162 x262)
     (blocked x164 x264)
     (blocked x166 x266)

; Level 2 X Blockages

     (blocked x214 x215)
     (blocked x215 x216)

     (blocked x222 x223)
     (blocked x223 x224)
     (blocked x224 x225)
     (blocked x225 x226)

     (blocked x232 x233)
     (blocked x233 x234)
     (blocked x235 x236)

     (blocked x242 x243)
     (blocked x243 x244)
     (blocked x244 x245)

     (blocked x253 x254)
     (blocked x254 x255)
     (blocked x255 x256)

     (blocked x261 x262)
     (blocked x262 x263)
     (blocked x263 x264)
     (blocked x264 x265)


; Level 2 Y Blockages

     (blocked x211 x221)
     (blocked x231 x241)
     (blocked x251 x251)

     (blocked x212 x222)
     (blocked x222 x232)
     (blocked x242 x252)
     (blocked x252 x262)

     (blocked x213 x223)
     (blocked x253 x263)

     (blocked x234 x244)
     (blocked x244 x254)
     (blocked x254 x264)

     (blocked x215 x225)
     (blocked x225 x235)
     (blocked x235 x245)
     (blocked x255 x265)

     (blocked x216 x226)
     (blocked x236 x246)
 
; Level 2-3 Z Blockages

     (blocked x212 x312)
     (blocked x213 x313)
     (blocked x214 x314)
     (blocked x215 x315)
     (blocked x216 x316)

     (blocked x221 x321)
     (blocked x223 x323)
     (blocked x224 x324)

     (blocked x231 x331)
     (blocked x232 x332)
     (blocked x233 x333)
     (blocked x234 x334)
     (blocked x235 x335)
     (blocked x236 x336)

     (blocked x241 x341)
     (blocked x242 x342)
     (blocked x243 x343)
     (blocked x244 x344)
     (blocked x245 x345)
     (blocked x246 x346)

     (blocked x251 x351)
     (blocked x252 x352)
     (blocked x253 x353)
     (blocked x254 x354)
     (blocked x255 x355)
     (blocked x256 x356)

     (blocked x261 x321)
     (blocked x262 x322)
     (blocked x264 x324)
     (blocked x265 x365)
     (blocked x266 x366)

; Level 3 X Blockages

     (blocked x322 x323)
     (blocked x325 x326)

     (blocked x331 x332)
     (blocked x332 x333)
     (blocked x333 x334)
     (blocked x334 x335)

     (blocked x341 x342)
     (blocked x342 x343)
     (blocked x344 x345)
     (blocked x345 x346)

     (blocked x353 x354)
     (blocked x354 x355)
     (blocked x355 x356)

     (blocked x361 x362)
     (blocked x362 x363)
     (blocked x363 x364)
     (blocked x365 x366)
 
; Level 3 Y Blockages

     (blocked x311 x321)
     (blocked x351 x361)

     (blocked x312 x322)
     (blocked x322 x332)
     (blocked x332 x342)
     (blocked x342 x352)
     (blocked x352 x362)

     (blocked x313 x323)
     (blocked x343 x353)

     (blocked x314 x324)
     (blocked x324 x334)
     (blocked x334 x344)

     (blocked x315 x325)
     (blocked x325 x335)

     (blocked x326 x336)

; Dynamic Blockages

;     NONE

   )

   (:goal 
       (and 
         (at robot x366)
       )
    )
)