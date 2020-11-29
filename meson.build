project('dining_philosophers', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

incl_dir = include_directories('include')
src_list = [
  'main.cpp',
  'src/chopsticks/behaviors/Available.cpp',
  'src/chopsticks/behaviors/Taken.cpp',
  'src/philosophers/Philosopher.cpp'
]

proj_root = meson.current_source_dir()
project_lib = proj_root+'/lib'
link_flags = ['-lpthread', '-L'+project_lib, '-lcaf_core', '-lcaf_io']

caf_dep = declare_dependency(
  link_args: link_flags
)

executable('dining_philosophers',
           sources: src_list,
           include_directories: incl_dir,
           dependencies: [caf_dep])
