Name:           runawfe-free
Version:        0.0.0.1
Release:        alt0.1
Summary:        RunaWFE app
Group:          Other
License:        LGPL-2.1
Url:            https://github.com/processtech/runawfe-free-alt-mobile
BuildArch:      noarch
Source:        %{name}-%{version}.tar.gz

BuildRequires: gcc-c++, meson, ninja-build
BuildRequires: pkgconfig(glibmm-2.68), pkgconfig(gtkmm-4.0)

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
