#include "LanguageAccessor.hpp"

std::map <std::string, const char*> LanguageProvider::Buffers::UIMessages = {

        { "main.build.en",   u8"Build: " },
        { "main.build.ru" ,  u8"Билд: "  },

        { "tabs.news.en",         u8"News"       },
        { "tabs.load.en",         u8"Load"       },
        { "tabs.set.en",        u8"Settings"     },

        { "tabs.news.ru",      u8"Новости"     },
        { "tabs.load.ru",      u8"Загрузка"    },
        { "tabs.set.ru",      u8"Настройки"    },

        { "news.title.en",                u8"Last news"         },
        { "news.about.en",                 u8"About"            },
        { "news.about.click.en",   u8"All text are clickable!" },

        { "news.title.ru",            u8"Последние новости"    },
        { "news.about.ru",               u8"Об проекте"        },
        { "news.about.click.ru",   u8"Весь текст кликабельный!" },

        { "news.info.en",         u8"Info"    },
        { "news.con.com.en",   u8"Community"  },
        { "news.con.dev.en",   u8"Developer"  },
        { "news.support.en",   u8"Support <3" },

        { "news.info.ru",     u8"Информация"    },
        { "news.con.com.ru",  u8"Сообщество"    },
        { "news.con.dev.ru",  u8"Разработчик"   },
        { "news.support.ru",  u8"Поддержка <3"  },

        { "news.info.txt.en",   u8"Welcome to the OTC-Loader project.\n\nWhat is that?\n\nThis project allows you to load OTC in CS:GO.\n\nWhy needed choose us?\n\n-> Availability: Price of our product = 0$.\n-> Responsiveness: We're listening to our community.\n-> Stability: Our product never crashes.\n\nThank you for choosing to use our product."  },
        { "news.info.txt.ru",   u8"Добро пожаловать в проект OTC-Loader.\n\nЧто это такое?\n\nЭтот проект позволяет вам загружать OTC в CS:GO.\n\nПочему стоит выбрать нас?\n\n-> Доступность: Цена нашего продукта = 0$.\n-> Отзывчивость: Мы прислушиваемся к сообществу.\n-> Стабильность: Наш продукт никогда не крашит.\n\nСпасибо, что решили использовать наш продукт."  },

        { "news.con.com.dis.en",         u8"Discord. [General node]"   },
        { "news.con.com.mail.en",               u8"Email."             },

        { "news.con.com.dis.ru",            u8"Дискорд. [Главная нода]" },
        { "news.con.com.mail.ru",                   u8"Почта."          },

        { "news.con.dev.vk.en",      u8"Vkontakte."  },
        { "news.con.dev.dis.en",     u8"Discord."    },
        { "news.con.dev.tg.en",      u8"Telegram."   },

        { "news.con.dev.vk.ru",    u8"Вконтакте." },
        { "news.con.dev.dis.ru",    u8"Дискорд."  },
        { "news.con.dev.tg.ru",     u8"Телеграм." },

        { "news.type.load.en",   u8"> LOADER" },
        { "news.type.otc.en",     u8"> OTC"   },

        { "news.type.load.ru", u8"> ЛОАДЕР" },

        { "news.ctg.add.en",     u8"*ADDED*"     },
        { "news.ctg.rew.en",    u8"*REWORKED*"   },
        { "news.ctg.rem.en",    u8"*REMOVED*"    },
        { "news.ctg.imp.en",    u8"*IMPROVED*"   },

        { "news.ctg.add.ru",   u8"*ДОБАВЛЕНО*"  },
        { "news.ctg.rew.ru", u8"*ПЕРАРАБОТАНО*" },
        { "news.ctg.rem.ru",    u8"*УДАЛЕНО*"   },
        { "news.ctg.imp.ru",    u8"*УЛУЧШЕНО*"  },

        { "load.rm.name.en",                                                u8"README"                                          },
        { "load.rm.imp.en",  u8"IMPORTANT: Half of the problems can be related to the injector itself or the injection method." },
        { "load.rm.rg.en",                                                 u8"FAQ:"                                             },

        { "load.rm.name.ru" ,                                            u8"ВАЖНО"                                             },
        { "load.rm.imp.ru",   u8"ВНИМАНИЕ: Половина проблем может быть связана с самим инжектором, или же методом инжекта."    },

        { "load.rm.is.render.en",      u8"OTC loaded and invoked, but when i try open menu, it's does not render."  },
        { "load.rm.is.render.slo.en",  u8"Enable multi-threaded rendering in CS:GO settings, and then inject OTC."  },
        { "load.rm.is.render.sls.en",  u8"Add a flag for disable d3x9 in the CS:GO startup params. [-disable_d3x9]" },

        { "load.rm.is.render.ru",           u8"OTC загружен, но когда я пытаюсь открыть меню оно не рендерится."       },
        { "load.rm.is.render.slo.ru",  u8"Включите многоядерную обработку в настройках CS:GO, и потом инжектите OTC."  },
        { "load.rm.is.render.sls.ru", u8"Добавьте флаг для отключения d3x9 в параметры запуска CS:GO. [-disable_d3x9]" },

        { "load.rm.is.crash.en",                 u8"The game crashes when I try inject OTC."          },
        { "load.rm.is.crash.slo.en",          u8"Make sure you have the latest version of OTC."       },
        { "load.rm.is.crash.sls.en", u8"Injector problems are also possible. [Try use Process Hacker/Any mmap injector]" },

        { "load.rm.is.crash.ru",                          u8"Игра крашится когда я инжекчу OTC."                        },
        { "load.rm.is.crash.slo.ru",                 u8"Убедитесь что у вас последняя версия OTC."                      },
        { "load.rm.is.crash.sls.ru", u8"Так же возможны проблемы с инжектором. [Попробуйте использовать Process Hacker/Любой mmap инжектор]" },

        { "load.rm.is.bug.en",              u8"I found [x] bug in [n] functions. What should I do ?"             },
        { "load.rm.is.bug.slo.en",                        u8"Record the bug on video."                           },
        { "load.rm.is.bug.sls.en", u8"Create a ticket with a description of the issue and a link to the video."  },
        { "load.rm.is.bug.slt.en",                  u8"Expect fixes in the next update."                         },

        { "load.rm.is.bug.ru",       u8"Я обнаружил [x] баг в [n] функции. Что мне делать?"      },
        { "load.rm.is.bug.slo.ru",               u8"Запишите баг на видео."                      },
        { "load.rm.is.bug.sls.ru", u8"Создайте тикет с описанием проблемы и ссылкой на видео."   },
        { "load.rm.is.bug.slt.ru",           u8"Ожидайте исправление в обновлении."              },

        { "load.rm.ik.name.en",     u8"Known issues: "   },
        { "load.rm.ik.name.ru", u8"Известные проблемы: " },

        { "load.rm.ik.ls.en",    u8"        <- Attachments chams doesn't work.\n        <- Weapon animations works weird."   },
        { "load.rm.ik.ls.ru", u8"        <- Attachments-чамсы не работают.\n        <- Анимации с оружием работают странно." },

        { "load.rm.tx.name.en",      u8"Special thanks: "     },
        { "load.rm.tx.name.ru", u8"Отдельная благодарность: " },

        { "load.rm.tx.dv.en",  u8"Developers: "  },
        { "load.rm.tx.dv.ru", u8"Разработчики: " },

        { "load.rm.tx.ds.en", u8"Designers: " },
        { "load.rm.tx.ds.ru", u8"Дизайнеры: " },

        { "load.rm.tx.ts.en", u8"Testers: " },
        { "load.rm.tx.ts.ru", u8"Тестеры: " },

        { "load.rm.tx.dvl.en",      u8"0x000cb. [Lead developer/Primal-engine]\n        <- Sneakyevil. [Second developer/chams.cc creator]\n        <- wzn. [OTv2 cracker]"    },
        { "load.rm.tx.dvl.ru", u8"0x000cb. [Главный разработчик/Primal-engine]\n        <- Sneakyevil. [Второй разработчик/Создатель chams.cc]\n        <- wzn. [OTv2 крякер]" },

        { "load.rm.tx.dsl.en",   u8"Sove. [Lead designer]\n        <- enQ. [Extensions designer]"  },
        { "load.rm.tx.dsl.ru", u8"Sove. [Главный дизайнер]\n        <- enQ. [Дизайнер расширений]" },

        { "load.rm.tx.tsl.en",             u8"Racoon [Lead tester/Friends]\n        <- HoShiMin [Tester/Friends]"            },
        { "load.rm.tx.tsl.ru", u8"Racoon [Главный тестировщик/Друг проекта]\n        <- HoShiMin [Тестировщик/Друг проекта]" },

        { "load.rm.tx.ur.en",      u8"And of course, thank you for using our product.\nWe try to do everything for free and with high quality."    },
        { "load.rm.tx.ur.ru", u8"И, конечно же, спасибо тебе за использование нашего продукта.\nМы стараемся сделать всё бесплатно и качественно." },

        { "load.ad.name.en",                           u8"ADDONS"                       },
        { "load.ad.oep.bef.en",                       u8"Before OEP"                    },
        { "load.ad.oep.aft.en",                       u8"After OEP"                     },
        { "load.ad.mod.add.en",                     u8"Add new module"                  },
        { "load.ad.mod.rem.en",                  u8"Remove last module"                 },
        { "load.ad.win.titl.en",                 u8"Select addon file."                 },
        { "load.ad.win.type.en",           u8"Dynamic Link Library [DLL]\0*.dll\0"      },

        { "load.ad.name.ru",                            u8"АДДОНЫ"                      },
        { "load.ad.oep.bef.ru",                       u8"Перед OEP"                     },
        { "load.ad.oep.aft.ru",                       u8"После OEP"                     },
        { "load.ad.mod.add.ru",                   u8"Добавить модуль"                   },
        { "load.ad.mod.rem.ru",                   u8"Удалить модуль"                    },
        { "load.ad.win.titl.ru",              u8"Выберите файл аддона."                 },
        { "load.ad.win.type.ru",  u8"Библиотека динамической компоновки [DLL]\0*.dll\0" },

        { "load.seg.name.en",    u8"SEGMENT" },
        { "load.seg.inf.en",       u8"Info"  },
        { "load.seg.deb.en",      u8"Debug"  },
        { "load.seg.out.en",     u8"Output"  },

        { "load.seg.name.ru",    u8"СЕГМЕНТ"  },
        { "load.seg.inf.ru",       u8"Лог"    },
        { "load.seg.deb.ru",     u8"Отладка"  },
        { "load.seg.out.ru",      u8"Вывод"   },

        { "load.seg.evn.en",  u8"*ATTENTION*\n\nSegment loading takes 5-10 seconds.\nOnce it loaded, you can open the menu via the 'INSERT' button.\nPress 'ENTER' to continue." },
        { "load.seg.cmp.en",  u8"'OTv2' segment has been successfully initialized.\n\nFor open the menu press 'INSERT'.\nGood luck and have fun !" },

        { "load.seg.evn.ru",  u8"*ВНИМАНИЕ*\n\nЗагрузка сегмента длится 5-10 секунд.\nПосле загрузки вы сможете открыть меню через кнопку 'INSERT'.\n\nЧтобы продолжить нажмите 'ENTER'." },
        { "load.seg.cmp.ru",  u8"Сегмент 'OTv2' успешно инициализирован.\n\nЧтобы открыть меню нажмите 'INSERT'. Удачи !\n" },

        { "load.seg.clbck.en",      u8"OTC -> Segment -> Load"      },
        { "load.seg.clbck.ru",  u8"OTC -> Сегмент -> Инициализация" },

        { "load.seg.dbg.en",   u8"Debug mode"  },
        { "load.seg.dbg.ru", u8"Режим отладки" },

        { "sett.name.en",       u8"Settings"    },
        { "sett.mod.us.en",     u8"User mode"   },
        { "sett.mod.dv.en",  u8"Developer mode" },

        { "sett.name.ru",          u8"Настройки"       },
        { "sett.mod.us.ru", u8"Пользовательский режим" },
        { "sett.mod.dv.ru",     u8"Продвинутый режим"  },

        { "sett.us.disrpc.en", u8"Discord RPC." },

        { "sett.dv.dbgload.en",      u8"Debug-load mode."      },
        { "sett.dv.dbgload.ru", u8"Режим отладочной загрузки." },

        { "sett.us.disrpc.pw.en", u8"Powered by primal-engine."  },
        { "sett.us.disrpc.pw.ru", u8"Основано на primal-engine." },

        { "sett.us.disrpc.in.en", u8"Initialization..." },
        { "sett.us.disrpc.in.ru", u8"Инициализация..."  },

        { "sett.us.disrpc.gm.en", u8"Playing in CS:GO." },
        { "sett.us.disrpc.gm.ru",  u8"Играет в CS:GO."  },

};

std::map <std::string, const char*> LanguageProvider::Buffers::PrimalMessages = {

        //Default.
        { "primal.hello.en", u8"Welcome to the primal-loader engine. \n\nOutput mode: Default output.\nSegment: OneTap v2." },
        { "primal.hello.ru", u8"Добро пожаловать в primal-loader. \n\nРежим вывода: Стандартный.\nСегмент: OneTap v2." },
        { "primal.prep.one.en", u8"Initialize engine..." },
        { "primal.prep.one.ru", u8"Инициализирую движок..." },
        { "primal.passed.one.en", u8"The engine is initialized." },
        { "primal.passed.one.ru", u8"Движок инициализирован." },
        { "primal.prep.sec.en", u8"Prepare OTv2 segment to update..." },
        { "primal.prep.sec.ru", u8"Подготавливаю сегмент OTv2 к обновлению..." },
        { "primal.passed.sec.en", u8"Segment OTv2 is ready to update." },
        { "primal.passed.sec.ru", u8"Сегмент OTv2 готов к обновлению." },
        { "primal.prep.seg.bef.en", u8"Currently updating: Offsets, interfaces, netvars..." },
        { "primal.prep.seg.bef.ru", u8"Сейчас обновляется: Оффсеты, интерфейсы, нетвары..." },
        { "primal.passed.seg.bef.en", u8"All data are up to date !" },
        { "primal.passed.seg.bef.ru", u8"Все данные успешно обновлены !" },
        { "primal.prep.thr.en", u8"Begin starting OTv2..." },
        { "primal.prep.thr.ru", u8"Начинаем запуск OTv2..." },
        { "primal.passed.thr.en", u8"OTv2 successfully started !" },
        { "primal.passed.thr.ru", u8"OTv2 успешно запущен !" },
        { "primal.prep.seg.aft.en", u8"Loading addons..."  },
        { "primal.prep.seg.aft.ru", u8"Загружаю аддоны..." },
        { "primal.passed.seg.aft.en", u8"Addons loaded !" },
        { "primal.passed.seg.aft.ru", u8"Аддоны загружены !" },
        { "primal.finish.en", u8"OTv2 is running and ready to work!\nThank you for using primal-loader.\n\n(Press 'ENTER' to exit boot mode)" },
        { "primal.finish.ru", u8"OTv2 запущен и готов к работе!\nСпасибо что воспользовались услугами primal-loader.\n\n(Чтобы выйти из загрузочного режима нажмите 'ENTER')" },

        //Debug.
        { "primal.hello.dbg.en", u8"Welcome to the primal-loader engine. \n\nOutput mode: Debug.\nSegment: OneTap v2."  },
        { "primal.hello.dbg.ru", u8"Добро пожаловать в primal-loader.\n\nРежим вывода: Отладочный.\nСегтмент: OneTap v2." },
        { "primal.prep.one.dbg.en", u8"Alloc memory and copy segment data..." },
        { "primal.prep.one.dbg.ru", u8"Выделяю память и копирую сегмент..." },
        { "primal.passed.one.dbg.en", u8"Segment copied to memory." },
        { "primal.passed.one.dbg.ru", u8"Сегмент выгружен в память." },
        { "primal.prep.sec.dbg.en", u8"Starting to reconstruct IAT and relocations..." },
        { "primal.prep.sec.dbg.ru", u8"Начинаю реконструировать IAT и релокации..." },
        { "primal.passed.sec.dbg.en", u8"IAT and relocations reconstructed." },
        { "primal.passed.sec.dbg.ru", u8"IAT и релокации реконструированы." },
        { "primal.prep.seg.bef.dbg.en", u8"Segment routine: Update offsets [89], update interfaces [4], and internal fixes." },
        { "primal.prep.seg.bef.dbg.ru", u8"Рутина сегмента: Обновить оффсеты, обновить интерфейсы, и внутренние фиксы." },
        { "primal.passed.seg.bef.dbg.en", u8"The segment has finished executing the routine." },
        { "primal.passed.seg.bef.dbg.ru", u8"Сегмент закончил выполнять рутину." },
        { "primal.prep.thr.dbg.en", u8"Invoke CRT_DllMain from segment... (OEP)" },
        { "primal.prep.thr.dbg.ru", u8"Вызываю CRT_DllMain сегмента... (OEP)" },
        { "primal.passed.thr.dbg.en", u8"CRT_DllMain invoked !" },
        { "primal.passed.thr.dbg.ru", u8"CRT_DllMain вызван !" },
        { "primal.prep.seg.aft.dbg.en", u8"Found segment addons queue ! Start loading to game..." },
        { "primal.prep.seg.aft.dbg.ru", u8"Сегмент имеет очередь на загрузку аддонов ! Начинаю загружать в игру..." },
        { "primal.passed.seg.aft.dbg.en", u8"All addons loaded !" },
        { "primal.passed.seg.aft.dbg.ru", u8"Все аддоны загружены !" },
        { "primal.finish.dbg.en", u8"The segment has been initialized.\nThank you for using primal-loader.\n\n(Press 'ENTER' to exit from boot mode)" },
        { "primal.finish.dbg.ru", u8"Сегмент инициализирован.\nСпасибо что воспользовались услугами primal-loader.\n\n(Чтобы выйти из загрузочного режима нажмите 'ENTER')" }


};

//WRAPPERS.

const char* LanguageProvider::GetRegionalMessageFromBuffer (LanguageProvider::Region region, LanguageProvider::BufferType buffer, std::string path) {

    auto GetTextFromMapWithRegionalIndicator = [](std::map <std::string, const char*> textMap, Region region, std::string path) {
        return textMap.at (path.append (".").append (LanguageProvider::RegionToText (region)));
    };

    switch (buffer) {

        default: return "Can't found target buffer.";
        case LanguageProvider::BufferType::UI: return GetTextFromMapWithRegionalIndicator (LanguageProvider::Buffers::UIMessages, region, path);
        case LanguageProvider::BufferType::PRIMAL:  return GetTextFromMapWithRegionalIndicator (LanguageProvider::Buffers::PrimalMessages, region, path);

    }

}

const char* LanguageProvider::RegionToText (LanguageProvider::Region region) {

    switch (region) {

        default:
        case LanguageProvider::Region::EN: return "en";
        case LanguageProvider::Region::RU: return "ru";

    }

}