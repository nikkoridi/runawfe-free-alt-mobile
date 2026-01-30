application_id = 'ru.runawfe.Runner'

icon_sizes = ['32x32', '48x48', '64x64', '96x96', '128x128']

foreach icon_size: icon_sizes
 icon_dir = 'hicolor' / icon_size / 'apps'
 install_data(
  icon_dir / ('@0@.png').format(application_id),
  install_dir: get_option('datadir') / 'icons' / icon_dir
)
endforeach
