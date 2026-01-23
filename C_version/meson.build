project('runawfe-free-alt-mobile',
   'c',
   default_options: ['warning_level=1'])
gtkdep = dependency('gtk4')
glibdep = dependency('glib-2.0')
dependencies_list = [gtkdep, glibdep]

executable(
'runawfe_free',
'main.c',
dependencies : dependencies_list,
install: true)
