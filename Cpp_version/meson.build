project('runawfe-free-alt-mobile',
   'cpp',
   default_options: ['warning_level=1'])
gtkdep = dependency('gtkmm-4.0')
glibdep = dependency('glibmm-2.68')
dependencies_list = [gtkdep, glibdep]


conf_data = configuration_data() 
conf_data.set('bindir', meson.current_build_dir())
desktop_file = configure_file(
  input: 'ru.runawfe.free.desktop.in',
  output: 'ru.runawfe.free.desktop',
  configuration: conf_data,
)

executable(
'runawfe_free',
'main.cpp',
dependencies : dependencies_list,
install: true)
