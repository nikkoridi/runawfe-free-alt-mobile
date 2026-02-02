Name:           runawfe-free
Version:        0.0.0.1
Release:        alt0.1
Summary:        RunaWFE app
Group:          Other
License:        LGPL-2.1
Url:            https://github.com/processtech/runawfe-free-alt-mobile
BuildArch:      noarch
Source:        %{name}-%{version}.tar.gz

Requires: glib2
BuildRequires: gcc, meson, ninja-build, glib2, libgtk4

%description
RunaWFE Free app for ALT Mobile.

%prep
%setup -q

%build
%meson
%meson_build

%install
%meson_install

%clean
rm -rf $RPM_BUILD_ROOT

%files
%{_bindir}/*

%set_verify_elf_method skip
