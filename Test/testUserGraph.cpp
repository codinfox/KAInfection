//
//  testUserGraph.cpp
//  Infection
//
//  Created by Zhihao Li on 10/24/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include "catch.hpp"
#include "UserGraph.hpp"

SCENARIO("Common usage of UserGraph", "[feature]") {
    GIVEN("a user graph with 5 users") {
        vector<User> users{User(0,{1,2}),User(1,{0}),User(2,{0}),User(3,{}),User(4,{})};
        REQUIRE(users.size() == 5);
        UserGraph graph(users);
        
        WHEN("find cluster by user with ID 1") {
            auto a = graph.findClusterByUser(1);
            THEN("we should get an empty set") {
                REQUIRE(a.size() == 3);
            }
        }
        
        WHEN("find a cluster by limited number 200, which is greater than the total amount") {
            auto a = graph.findClusterByAmount(200);
            THEN("we should get a number of users slightly greater than 200") {
                REQUIRE(a.size() == 5);
            }
        }
    }
    
    GIVEN("a user graph with 1000 users") {
        vector<User> users{User(0,{22,18,3,4,24}),User(1,{10,7,13,16}),User(2,{3,24,4,19}),User(3,{24,18,21,2,0}),User(4,{11,14,0,22,2}),User(5,{13,17,5,10}),User(6,{12,15,11}),User(7,{11,1,9,19,17}),User(8,{14}),User(9,{20,18,13,22,7}),User(10,{22,1,13,15,5}),User(11,{14,4,15,13,7,6}),User(12,{13,6,21}),User(13,{14,5,1,12,10,9,11}),User(14,{13,8,11,14,4}),User(15,{22,15,10,11,6}),User(16,{24,1}),User(17,{7,5}),User(18,{0,18,3,9}),User(19,{24,19,7,2}),User(20,{22,9}),User(21,{24,22,12,3}),User(22,{24,0,21,10,9,20,4,15}),User(23,{}),User(24,{16,3,19,21,2,22,0}),User(25,{26,27,25}),User(26,{25}),User(27,{25}),User(28,{34,36}),User(29,{32,33}),User(30,{34,35,30}),User(31,{36,35,33}),User(32,{36,29}),User(33,{35,31,29}),User(34,{30,28}),User(35,{33,31,30}),User(36,{32,31,28}),User(37,{}),User(38,{40,38}),User(39,{}),User(40,{47,43,38,44}),User(41,{49,46}),User(42,{46,45}),User(43,{49,48,46,44,50,40,45}),User(44,{45,46,49,52,43,40}),User(45,{42,44,53,48,43}),User(46,{42,43,41,44}),User(47,{40,52,48}),User(48,{45,43,47}),User(49,{41,50,43,44}),User(50,{52,49,43}),User(51,{53}),User(52,{50,47,44}),User(53,{45,51}),User(54,{62,65,55}),User(55,{63,62,66,54,59}),User(56,{67,64}),User(57,{64,61,58,57,62,67}),User(58,{60,61,58,67,57}),User(59,{60,55}),User(60,{61,59,63,58}),User(61,{57,65,60,58}),User(62,{54,57,65,55}),User(63,{67,55,60}),User(64,{57,65,56}),User(65,{67,62,54,64,66,61}),User(66,{65,55}),User(67,{56,65,58,63,57}),User(68,{69,71,68,70,72}),User(69,{70,68}),User(70,{69,70,71,68}),User(71,{72,70,68}),User(72,{71,68}),User(73,{74,73}),User(74,{73,74}),User(75,{78,76,84}),User(76,{79,84,81,75}),User(77,{82,78}),User(78,{82,83,78,77,80,75}),User(79,{80,79,76,82}),User(80,{80,79,84,83,78}),User(81,{76}),User(82,{77,78,84,79}),User(83,{80,78}),User(84,{84,82,76,80,75}),User(85,{92,85,90,94}),User(86,{103,98,99}),User(87,{97,90}),User(88,{97}),User(89,{98}),User(90,{101,87,90,105,85}),User(91,{92,104,93}),User(92,{105,98,104,85,96,91}),User(93,{95,103,101,91}),User(94,{103,104,94,85}),User(95,{99,93}),User(96,{103,98,92}),User(97,{87,88}),User(98,{106,86,89,99,92,103,96}),User(99,{95,98,106,86}),User(100,{105,100,102}),User(101,{102,101,93,90}),User(102,{101,100}),User(103,{86,96,106,105,94,98,93}),User(104,{94,92,91}),User(105,{106,92,103,100,90}),User(106,{105,99,98,103}),User(107,{116,111,119,108,110,117}),User(108,{108,117,107,116}),User(109,{}),User(110,{115,107}),User(111,{116,107,114}),User(112,{117}),User(113,{117,113}),User(114,{118,111}),User(115,{119,110,117}),User(116,{107,111,108}),User(117,{108,115,113,117,112,118,107}),User(118,{114,117}),User(119,{119,115,107}),User(120,{143,134,125,141,121}),User(121,{139,145,134,120,142,137}),User(122,{142}),User(123,{133,125,130,129}),User(124,{136,140,135}),User(125,{146,123,134,139,130,120}),User(126,{134,139,137,130,135}),User(127,{138,135}),User(128,{140,135,141,136,139}),User(129,{143,129,140,130,137,123}),User(130,{141,125,126,139,129,123}),User(131,{}),User(132,{}),User(133,{136,123}),User(134,{121,126,125,120}),User(135,{124,127,138,128,126}),User(136,{141,124,133,128}),User(137,{139,129,146,126,121}),User(138,{138,142,127,145,135}),User(139,{121,126,137,128,130,125}),User(140,{142,128,124,129,144}),User(141,{136,128,120,130}),User(142,{144,138,122,140,121}),User(143,{129,120}),User(144,{142,140}),User(145,{121,138}),User(146,{125,137}),User(147,{159,153,160,150}),User(148,{156,164,155,148}),User(149,{150,152,154,159}),User(150,{149,165,151,152,147}),User(151,{153,154,160,150}),User(152,{163,153,150,159,149}),User(153,{164,151,162,163,152,158,147}),User(154,{160,155,161,151,149}),User(155,{154,148}),User(156,{165,158,148}),User(157,{163}),User(158,{153,165,161,156}),User(159,{147,152,164,149}),User(160,{147,160,154,151}),User(161,{158,163,164,154}),User(162,{163,153}),User(163,{153,157,152,162,161}),User(164,{161,159,153,148}),User(165,{156,158,150}),User(166,{173,167,182}),User(167,{172,174,166}),User(168,{175,173,177}),User(169,{186,178,185,184}),User(170,{173,184}),User(171,{174,172,182}),User(172,{175,177,178,167,183,171}),User(173,{168,180,175,170,166}),User(174,{180,181,176,182,171,167}),User(175,{182,172,179,168,173}),User(176,{174,177}),User(177,{185,176,187,172,168}),User(178,{169,182,172}),User(179,{175}),User(180,{184,174,180,173}),User(181,{181,174,184}),User(182,{175,174,178,171,166}),User(183,{172}),User(184,{181,180,170,169}),User(185,{177,169}),User(186,{187,169}),User(187,{186,177}),User(188,{}),User(189,{190,192,211,213}),User(190,{200,189}),User(191,{213}),User(192,{201,204,189}),User(193,{197,200,211,206}),User(194,{201,202}),User(195,{206,205,200,208}),User(196,{197,210,205,201}),User(197,{211,196,208,193}),User(198,{204}),User(199,{210,205,200,207}),User(200,{199,205,195,190,193}),User(201,{192,204,194,196}),User(202,{211,202,194}),User(203,{}),User(204,{198,206,201,192}),User(205,{212,199,200,195,196}),User(206,{204,195,193}),User(207,{212,199}),User(208,{197,195}),User(209,{212}),User(210,{213,199,196}),User(211,{197,202,213,193,189}),User(212,{213,209,207,205}),User(213,{212,210,211,191,189}),User(214,{227,234,226,223}),User(215,{223,220,225}),User(216,{224,228,223,217,226}),User(217,{228,231,220,218,216,226}),User(218,{226,223,218,217}),User(219,{225,234,229}),User(220,{232,224,217,230,225,215}),User(221,{233,221,232}),User(222,{230,225,224,232,233,228}),User(223,{216,218,233,226,215,214}),User(224,{216,226,225,220,222}),User(225,{234,222,233,227,224,219,220,215}),User(226,{230,223,218,217,216,224,214}),User(227,{227,234,214,225}),User(228,{216,217,232,222}),User(229,{219}),User(230,{220,222,233,226}),User(231,{233,231,232,217}),User(232,{220,228,222,231,221}),User(233,{231,230,225,223,222,221}),User(234,{225,227,219,214}),User(235,{237}),User(236,{}),User(237,{235,237}),User(238,{238,249}),User(239,{247,242}),User(240,{242,246,241,244,243}),User(241,{246,245,240}),User(242,{242,245,240,239}),User(243,{246,243,244,240}),User(244,{249,243,240}),User(245,{249,241,245,242}),User(246,{248,243,247,240,241}),User(247,{248,239,246}),User(248,{246,249,247}),User(249,{245,244,248,238}),User(250,{264,254}),User(251,{253,264,269,258,267,256}),User(252,{}),User(253,{259,255,262,251}),User(254,{264,265,250}),User(255,{267,264,256,253}),User(256,{262,258,255,256,251}),User(257,{263,269,257}),User(258,{256,251}),User(259,{269,266,253,264,260,268}),User(260,{263,259}),User(261,{265,268}),User(262,{256,253}),User(263,{268,264,257,260}),User(264,{269,259,251,263,254,255,250}),User(265,{261,254}),User(266,{259}),User(267,{269,251,255}),User(268,{263,261,259}),User(269,{259,264,267,257,251}),User(270,{}),User(271,{}),User(272,{272,277}),User(273,{277}),User(274,{280}),User(275,{281}),User(276,{279,280}),User(277,{280,273,272}),User(278,{281,280}),User(279,{281,276}),User(280,{277,278,276,274}),User(281,{279,278,281,275}),User(282,{284}),User(283,{288,289}),User(284,{286,290,282}),User(285,{286,285,287}),User(286,{287,284,290,285}),User(287,{286,290,285}),User(288,{290,283}),User(289,{290,283}),User(290,{286,288,287,289,284}),User(291,{301,299,295,292}),User(292,{298,291}),User(293,{299}),User(294,{296,297,300}),User(295,{297,296,291}),User(296,{297,300,295,294}),User(297,{295,296,301,294}),User(298,{292}),User(299,{300,291,293}),User(300,{300,296,299,294}),User(301,{291,297}),User(302,{327,315,313}),User(303,{}),User(304,{314,316}),User(305,{307,319}),User(306,{325,313,326,311,314}),User(307,{316,311,305}),User(308,{316,310,327}),User(309,{311}),User(310,{327,308,318,320,322,312}),User(311,{312,307,309,320,324,306}),User(312,{323,311,312,320,310}),User(313,{321,306,324,302}),User(314,{317,306,304}),User(315,{328,318,326,302}),User(316,{325,307,308,304}),User(317,{326,314,325,320,319,323}),User(318,{323,315,310}),User(319,{322,327,317,305}),User(320,{317,312,311,310}),User(321,{322,313}),User(322,{327,321,310,319}),User(323,{328,318,312,317}),User(324,{313,311}),User(325,{328,317,306,316}),User(326,{306,317,315}),User(327,{302,310,327,322,319,308}),User(328,{323,325,315}),User(329,{349,347}),User(330,{337,333,341}),User(331,{347,334,345,338,342,332}),User(332,{352,331}),User(333,{343,346,350,330}),User(334,{352,334,346,331}),User(335,{339,348,342}),User(336,{345,348,338}),User(337,{351,350,330,338,347}),User(338,{342,337,331,336}),User(339,{349,340,345,335}),User(340,{351,339,345}),User(341,{330}),User(342,{343,338,335,331}),User(343,{342,333}),User(344,{351,348}),User(345,{336,331,340,339}),User(346,{334,348,333}),User(347,{331,329,347,337}),User(348,{344,348,346,336,335}),User(349,{329,339}),User(350,{337,333}),User(351,{344,337,340}),User(352,{332,334}),User(353,{361,356,357,355,359}),User(354,{359,360}),User(355,{360,353}),User(356,{361,360,359,358,353}),User(357,{353}),User(358,{356}),User(359,{362,354,356,353}),User(360,{355,356,354}),User(361,{353,356,362}),User(362,{361,359}),User(363,{389,365,376,368,373}),User(364,{380,386,366}),User(365,{366,371,363,372}),User(366,{383,372,365,378,389,364}),User(367,{375,374,384,368,388}),User(368,{385,370,363,387,367}),User(369,{384,388,381}),User(370,{381,374,368}),User(371,{376,384,377,385,365}),User(372,{379,366,365}),User(373,{387,378,363}),User(374,{367,385,370}),User(375,{389,387,367}),User(376,{380,371,386,379,378,363}),User(377,{379,383,371}),User(378,{388,373,386,366,376}),User(379,{384,385,372,377,376}),User(380,{380,376,364}),User(381,{388,370,369}),User(382,{385}),User(383,{377,366}),User(384,{371,379,369,367}),User(385,{387,379,368,371,382,374}),User(386,{364,378,376}),User(387,{388,373,368,385,375}),User(388,{378,381,369,387,367}),User(389,{375,363,366}),User(390,{397,411,416}),User(391,{410,414,403,400,401,391}),User(392,{398,403,392,411,401}),User(393,{411,393}),User(394,{416}),User(395,{405}),User(396,{408,401,407,404,414,400}),User(397,{407,390}),User(398,{414,401,408,392}),User(399,{404,407,410,400,403}),User(400,{406,414,399,410,409,396,402,391}),User(401,{398,392,396,391}),User(402,{407,411,406,400}),User(403,{416,408,404,392,403,391,399,407}),User(404,{415,396,414,403,409,399}),User(405,{395}),User(406,{402,400}),User(407,{403,408,397,402,399,396}),User(408,{396,407,408,403,398}),User(409,{404,414,400}),User(410,{399,416,391,400}),User(411,{390,402,392,393}),User(412,{}),User(413,{414}),User(414,{404,398,409,400,396,413,391}),User(415,{404}),User(416,{403,394,410,390}),User(417,{}),User(418,{418,426,422}),User(419,{422}),User(420,{421,426,425,420}),User(421,{426,422,425,420}),User(422,{421,419,418}),User(423,{425}),User(424,{}),User(425,{423,421,420}),User(426,{421,420,418}),User(427,{438}),User(428,{437,434,441,431}),User(429,{435,431,441,438}),User(430,{433,441,431,440}),User(431,{430,429,438,433,428}),User(432,{432}),User(433,{431,433,430}),User(434,{435,438,428}),User(435,{441,439,434,429}),User(436,{440,439}),User(437,{441,437,428}),User(438,{427,431,434,429}),User(439,{436,435}),User(440,{436,430}),User(441,{437,428,430,435,429}),User(442,{460,447,457,463,462,451}),User(443,{449}),User(444,{448,455,460}),User(445,{463,447,462,449,446}),User(446,{447,449,445}),User(447,{446,459,442,445}),User(448,{455,457,452,464,444}),User(449,{461,460,452,451,446,456,445,443}),User(450,{458,457}),User(451,{463,453,449,462,442}),User(452,{449,448}),User(453,{451,457}),User(454,{461}),User(455,{444,455,463,448}),User(456,{458,449}),User(457,{450,453,448,462,442}),User(458,{464,450,461,456,458}),User(459,{461,459,462,447}),User(460,{449,444,442}),User(461,{463,458,454,449,459}),User(462,{459,442,457,451,445}),User(463,{451,461,455,445,442}),User(464,{458,448}),User(465,{468,467,466,469}),User(466,{467,468,470,465,471}),User(467,{466,471,465}),User(468,{470,465,466}),User(469,{471,470,465}),User(470,{470,466,469,468}),User(471,{469,467,466}),User(472,{472}),User(473,{486,493}),User(474,{490,475,479,483}),User(475,{488,487,484,474}),User(476,{492,487,480,476}),User(477,{489,481,486}),User(478,{490,480,482}),User(479,{490,488,474}),User(480,{484,476,478}),User(481,{477}),User(482,{487,492,493,478}),User(483,{492,484,474}),User(484,{492,483,480,475}),User(485,{486,488}),User(486,{485,491,488,473,477}),User(487,{488,476,482,475}),User(488,{493,475,486,487,485,479}),User(489,{489,477}),User(490,{474,479,478}),User(491,{491,486}),User(492,{476,484,483,482}),User(493,{482,488,473}),User(494,{}),User(495,{508,505,497,502,506}),User(496,{509,496,506}),User(497,{498,504,499,495}),User(498,{508,500,507,497,506}),User(499,{501,508,497}),User(500,{509,505,498}),User(501,{505,499,507}),User(502,{504,495}),User(503,{504}),User(504,{507,505,506,497,502,503}),User(505,{504,501,505,500,495}),User(506,{504,508,498,496,495}),User(507,{509,504,498,501}),User(508,{495,498,506,499}),User(509,{496,500,507}),User(510,{521,520,515}),User(511,{520,514}),User(512,{520,514,513,512}),User(513,{521,512,517}),User(514,{518,517,512,511,521}),User(515,{521,518,520,510}),User(516,{518,517}),User(517,{514,516,513}),User(518,{519,514,516,515}),User(519,{518,520,519}),User(520,{512,510,515,511,519}),User(521,{513,510,515,514}),User(522,{537}),User(523,{529,546,526,532}),User(524,{545,542}),User(525,{525,532,542}),User(526,{545,542,536,528,523}),User(527,{546,541}),User(528,{544,546,531,526}),User(529,{538,523,539,535}),User(530,{541,532}),User(531,{540,531,532,528}),User(532,{531,545,530,525,523}),User(533,{542,546,539}),User(534,{544,535,537}),User(535,{534,529}),User(536,{526}),User(537,{545,544,534,522}),User(538,{539,529}),User(539,{542,538,533,529}),User(540,{544,543,531}),User(541,{527,545,530}),User(542,{539,533,524,526,545,525}),User(543,{540}),User(544,{528,544,534,540,537}),User(545,{532,524,537,526,541,542}),User(546,{527,523,533,528}),User(547,{555,563}),User(548,{564,553}),User(549,{557,554,550,558}),User(550,{564,559,549,557,561}),User(551,{555}),User(552,{560,564,557}),User(553,{560,548}),User(554,{558,555,564,554,549}),User(555,{558,551,554,557,547}),User(556,{563,560,564}),User(557,{549,552,555,550}),User(558,{564,563,555,558,562,554,549}),User(559,{561,562,550}),User(560,{553,552,556}),User(561,{559,550}),User(562,{559,558}),User(563,{556,558,547}),User(564,{548,554,558,550,556,552}),User(565,{571,569}),User(566,{567,568}),User(567,{573,566,567,572}),User(568,{574,573,570,572,566}),User(569,{573,565}),User(570,{568}),User(571,{565,574}),User(572,{573,568,567}),User(573,{568,567,572,574,569}),User(574,{574,568,573,571}),User(575,{591,587,581,586,578,594}),User(576,{594,591,588,583}),User(577,{588,585,584}),User(578,{587,591,586,575}),User(579,{590,581,587}),User(580,{590,595}),User(581,{582,575,579}),User(582,{584,581}),User(583,{595,576}),User(584,{582,577,584}),User(585,{591,587,577}),User(586,{594,578,575}),User(587,{594,578,593,579,585,575}),User(588,{588,576,577}),User(589,{594,593,590}),User(590,{593,580,595,579,589}),User(591,{576,578,575,585}),User(592,{}),User(593,{590,589,587}),User(594,{587,589,576,586,575}),User(595,{583,590,580}),User(596,{598,606,605}),User(597,{603,602,606,601,599}),User(598,{600,598,596}),User(599,{603,600,597}),User(600,{602,601,605,599,598}),User(601,{600,597,606,601}),User(602,{597,600}),User(603,{605,597,599}),User(604,{605}),User(605,{603,604,600,596}),User(606,{597,601,596}),User(607,{613,608}),User(608,{614,609,612,607,615}),User(609,{612,614,608,615}),User(610,{613}),User(611,{615}),User(612,{615,609,613,608}),User(613,{610,612,607}),User(614,{608,614,609}),User(615,{611,612,609,608}),User(616,{623,616,627,629}),User(617,{625,629,630,619,623,633}),User(618,{632,625,621,618}),User(619,{621,626,617}),User(620,{629,623,627}),User(621,{626,618,624,634,619}),User(622,{631}),User(623,{616,626,627,617,620}),User(624,{621,628}),User(625,{633,631,630,629,618,617}),User(626,{632,623,621,619}),User(627,{627,623,620,616}),User(628,{629,624}),User(629,{617,628,625,620,616}),User(630,{634,625,632,617}),User(631,{625,632,622,633}),User(632,{618,633,630,631,626}),User(633,{625,631,632,617}),User(634,{634,630,621}),User(635,{646,643,638,639,644}),User(636,{638}),User(637,{647,641,646,640}),User(638,{647,635,638,641,636}),User(639,{643,640,635}),User(640,{645,639,637}),User(641,{644,642,637,645,638}),User(642,{641}),User(643,{635,647,639}),User(644,{647,646,641,645,635}),User(645,{644,641,640}),User(646,{646,644,635,647,637}),User(647,{646,647,637,644,638,643}),User(648,{658,654,653,656,667,651}),User(649,{662}),User(650,{669,658,665,655,667}),User(651,{665,659,668,663,648}),User(652,{662,655,664,653,663,658}),User(653,{658,660,665,657,652,648}),User(654,{669,655,665,663,648}),User(655,{661,652,654,650}),User(656,{664,660,648}),User(657,{662,669,658,653}),User(658,{662,650,653,648,657,652}),User(659,{667,666,661,651}),User(660,{656,668,663,653}),User(661,{659,663,655}),User(662,{657,652,658,649}),User(663,{660,654,652,661,651}),User(664,{669,668,656,652}),User(665,{666,651,667,650,654,653}),User(666,{666,659,669,665}),User(667,{659,665,650,648}),User(668,{660,651,664}),User(669,{650,654,664,666,657}),User(670,{678,670,684}),User(671,{674}),User(672,{681,680,684,677,682,676}),User(673,{680,684,673}),User(674,{680,679,683,676,671}),User(675,{679,677,680,676}),User(676,{681,679,675,684,674,677,672}),User(677,{672,684,676,680,675}),User(678,{682,670}),User(679,{676,675,674}),User(680,{682,673,674,672,677,675}),User(681,{683,672,676}),User(682,{678,680,672}),User(683,{681,674}),User(684,{676,673,677,672,670}),User(685,{695,694,692,687}),User(686,{695,692}),User(687,{693,685}),User(688,{689,694}),User(689,{694,692,690,693,688}),User(690,{691,689}),User(691,{690,692}),User(692,{689,691,686,695,685}),User(693,{694,689,687}),User(694,{689,685,693,688}),User(695,{685,692,686}),User(696,{707,706,715}),User(697,{712,715,710}),User(698,{720,716,706,718,707,703,708}),User(699,{711,713}),User(700,{721,702,704,708,711,716}),User(701,{}),User(702,{703,713,716,700,710}),User(703,{719,698,711,717,702}),User(704,{700}),User(705,{715}),User(706,{698,696}),User(707,{720,696,717,713,698}),User(708,{715,700,698}),User(709,{}),User(710,{715,712,702,697}),User(711,{719,699,703,700}),User(712,{710,717,697}),User(713,{721,707,702,719,699}),User(714,{}),User(715,{720,697,708,721,710,705,696}),User(716,{721,698,702,700}),User(717,{703,712,707}),User(718,{698}),User(719,{711,713,703}),User(720,{698,715,707}),User(721,{713,716,721,700,715}),User(722,{}),User(723,{730,731}),User(724,{729,727,726}),User(725,{733,731,727,732}),User(726,{733,731,732,724,729,734}),User(727,{724,725}),User(728,{732,729}),User(729,{734,724,733,728,731,726}),User(730,{733,723,730}),User(731,{732,726,725,729,723}),User(732,{728,731,726,725}),User(733,{729,726,725,730}),User(734,{729,726}),User(735,{}),User(736,{744}),User(737,{738,745,746,739,744}),User(738,{743,741,742,737,744,745}),User(739,{746,745,737}),User(740,{}),User(741,{744,738}),User(742,{744,738}),User(743,{744,738}),User(744,{741,743,738,742,737,736}),User(745,{746,739,738,737}),User(746,{739,746,745,737}),User(747,{770,756}),User(748,{768,755,762,751}),User(749,{767,766,751,755}),User(750,{766,758,760}),User(751,{767,765,749,748}),User(752,{771,756,759}),User(753,{772,769,758,771,755,764}),User(754,{755,766}),User(755,{761,759,748,753,754,760,749}),User(756,{766,761,763,752,747}),User(757,{766,758}),User(758,{769,753,772,757,750}),User(759,{755,772,752}),User(760,{769,764,755,750}),User(761,{756,755,763}),User(762,{771,748}),User(763,{761,756}),User(764,{760,753}),User(765,{767,751}),User(766,{769,756,750,757,749,754}),User(767,{751,765,749}),User(768,{770,748}),User(769,{760,766,769,753,758}),User(770,{768,747}),User(771,{762,752,753}),User(772,{759,753,758}),User(773,{785,783,784,774}),User(774,{786,780,778,773}),User(775,{786}),User(776,{778,786,777}),User(777,{778,776}),User(778,{785,777,782,774,776}),User(779,{785,782}),User(780,{786,784,774}),User(781,{}),User(782,{779,778}),User(783,{773,784}),User(784,{784,773,783,785,780}),User(785,{786,773,778,784,779}),User(786,{776,785,780,775,774}),User(787,{789,799,796}),User(788,{794}),User(789,{789,792,787}),User(790,{803,795,799,801,796}),User(791,{}),User(792,{797,801,796,789}),User(793,{794}),User(794,{801,795,788,793}),User(795,{794,790}),User(796,{801,790,792,787}),User(797,{792}),User(798,{800}),User(799,{790,787}),User(800,{798}),User(801,{794,790,792,796}),User(802,{}),User(803,{790}),User(804,{814,813,812,818,807,816,808}),User(805,{808,817,806,815}),User(806,{816,819,808,813,805}),User(807,{810,804,808}),User(808,{805,807,806,819,804}),User(809,{817,814,811}),User(810,{813,810,807}),User(811,{816,809}),User(812,{818,816,814,804,819}),User(813,{810,819,804,806}),User(814,{812,816,804,809}),User(815,{817,805}),User(816,{806,817,812,811,814,804}),User(817,{819,809,816,815,805}),User(818,{812,804}),User(819,{808,813,817,812,806}),User(820,{}),User(821,{832,830,831,836}),User(822,{841,834,840}),User(823,{835,834,827}),User(824,{841,827}),User(825,{839}),User(826,{833,841}),User(827,{832,823,831,824}),User(828,{836,841,834}),User(829,{841}),User(830,{833,821}),User(831,{833,821,837,827}),User(832,{827,821}),User(833,{834,830,826,841,831}),User(834,{822,833,823,828}),User(835,{823,836,835}),User(836,{828,835,821}),User(837,{839,831}),User(838,{839}),User(839,{838,825,840,837}),User(840,{839,822}),User(841,{824,833,822,829,828,826}),User(842,{843,842}),User(843,{843,842}),User(844,{850,851,846,849}),User(845,{856,854,849,847}),User(846,{856,847,857,844}),User(847,{853,849,846,855,845}),User(848,{857,863}),User(849,{858,861,845,847,844}),User(850,{860,844,859}),User(851,{858,844}),User(852,{864,860}),User(853,{855,862,847,854,858}),User(854,{860,845,853}),User(855,{861,856,853,858,847}),User(856,{862,857,845,855,846}),User(857,{857,863,848,856,846}),User(858,{851,860,849,859,855,853}),User(859,{864,858,850}),User(860,{850,861,858,863,852,854}),User(861,{860,855,849}),User(862,{856,853}),User(863,{860,857,848}),User(864,{852,859,864}),User(865,{867,881,871}),User(866,{880,877,867,879}),User(867,{866,865,883,887}),User(868,{891,879,875}),User(869,{871,869}),User(870,{891,889}),User(871,{885,882,877,879,869,865}),User(872,{880,884,879,878,892}),User(873,{874}),User(874,{891,880,873}),User(875,{868}),User(876,{887,877,879}),User(877,{871,866,876,879}),User(878,{882,872,878}),User(879,{889,871,872,866,877,868,876}),User(880,{874,866,892,872}),User(881,{890,865}),User(882,{882,878,871}),User(883,{867}),User(884,{872,891,890}),User(885,{871}),User(886,{893,890}),User(887,{889,876,867}),User(888,{}),User(889,{870,887,879}),User(890,{884,886,881}),User(891,{870,874,884,868}),User(892,{880,872}),User(893,{886}),User(894,{908,902,898,901,896,900}),User(895,{900,906,904,897}),User(896,{898,905,894,899}),User(897,{908,903,901,899,900,905,895}),User(898,{909,894,905,902,899,896}),User(899,{904,901,903,898,908,897,906,896}),User(900,{903,908,897,906,895,894}),User(901,{894,899,897}),User(902,{906,907,894,898}),User(903,{897,905,900,899}),User(904,{904,899,909,905,895}),User(905,{904,903,898,897,896}),User(906,{902,899,900,895}),User(907,{909,902}),User(908,{897,909,899,894,900}),User(909,{898,908,907,904}),User(910,{922,929,921,926,916}),User(911,{928,921}),User(912,{917,913,916}),User(913,{914,928,912}),User(914,{929,926,921,913}),User(915,{927,919}),User(916,{929,916,917,912,920,910}),User(917,{925,919,912,920,921,916}),User(918,{923}),User(919,{919,917,915}),User(920,{924,921,927,916,925,917}),User(921,{920,910,917,914,911}),User(922,{924,910}),User(923,{918}),User(924,{929,920,928,927,922}),User(925,{917,920}),User(926,{914,910}),User(927,{924,915,920}),User(928,{911,924,913}),User(929,{916,924,914,910}),User(930,{954,951,943,937,942}),User(931,{931,953,943,940}),User(932,{941}),User(933,{940,942,948,938}),User(934,{943,942,938,937,952,934,935}),User(935,{950,934}),User(936,{949,946,941}),User(937,{950,939,943,954,934,930}),User(938,{946,940,934,947,933}),User(939,{954,950,937}),User(940,{952,938,933,931}),User(941,{949,932,936}),User(942,{947,934,933,930}),User(943,{937,954,934,931,930}),User(944,{951}),User(945,{953}),User(946,{949,936,948,938}),User(947,{950,942,938}),User(948,{946,949,933,948}),User(949,{946,941,936,953,948}),User(950,{935,939,947,937}),User(951,{951,930,944}),User(952,{940,954,934}),User(953,{931,945,949}),User(954,{939,930,943,952,937}),User(955,{955}),User(956,{959,958}),User(957,{959,957}),User(958,{959,956}),User(959,{958,957,956}),User(960,{972,968,964,969,966}),User(961,{973,963}),User(962,{971,966,975}),User(963,{969,961,973}),User(964,{960}),User(965,{974,967}),User(966,{962,960}),User(967,{973,970,965,975}),User(968,{973,969,971,970,960}),User(969,{968,963,960}),User(970,{974,968,967}),User(971,{968,962}),User(972,{974,960}),User(973,{961,967,968,963}),User(974,{972,965,970}),User(975,{967,962}),User(976,{984}),User(977,{980,982,981,984,979}),User(978,{984,979,981}),User(979,{978,977}),User(980,{977}),User(981,{978,982,977}),User(982,{983,981,977}),User(983,{983,982}),User(984,{978,977,976}),User(985,{995,986,999,987,993}),User(986,{987,985}),User(987,{998,995,994,989,992,986,985}),User(988,{991}),User(989,{999,997,987}),User(990,{992,996,991,999}),User(991,{998,997,993,988,990,995}),User(992,{996,994,987,998,995,990}),User(993,{991,994,999,995,996,985}),User(994,{995,993,987,992}),User(995,{999,994,985,993,998,987,992,991}),User(996,{993,992,990}),User(997,{991,998,999,989}),User(998,{995,991,987,997,992}),User(999,{995,997,993,989,990,985})};
        REQUIRE(users.size() == 1000);
        UserGraph graph(users);
        
        WHEN("find cluster by user with ID 791") {
            auto a = graph.findClusterByUser(791);
            THEN("we should have only one element which is 791 itself") {
                REQUIRE(a.size() == 1);
                REQUIRE(*a.begin() == 791);
            }
        }
        
        WHEN("find a cluster by limited number 200") {
            auto a = graph.findClusterByAmount(200);
            THEN("we should get a number of users slightly greater than 200") {
                REQUIRE(a.size() >= 200);
            }
        }
    }
}