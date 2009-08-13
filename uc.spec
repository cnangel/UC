%define _tmppath %{_topdir}/BUILDROOT

Name: uc
Version: 0.0.2
Release: 4

Summary: template for automake
License: LGPL
Group: Development/Libraries
Url: http://my.huhoo.net/study
Source0: %{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id} -u -n)

%define PACKAGE_HOME %{_datadir}/uc

Packager: Cnangel <junliang.li@alibaba-inc.com>
#Requires: 
#BuildRequires: 

%description
%{name} is a template for automake.

%package devel
Summary: Header files, libraries for %{name}.
Group: %{group}
Requires: %{name} = %{version}-%{release} 

%description devel
This package contains the header files and static libraries for %{name}.
If you like to develop programs using %{name}, you will need to install %{name}-devel.

%package data
Summary: Data for %{name}.
Group: %{group}
Requires: %{name} = %{version}-%{release} 

%description data
This package contains the training data, testing data and some useful data for %{name}, if need, you must install %{name}-data.

%package doc
Summary: Development documentation for %{name}.
Group: %{group}
Requires: %{name} = %{version}-%{release} 

%description doc
This package contains the development documentation and introduction or information for %{name}.
If you want to known develop programs and application about %{name}, you will need to install %{name}-doc.

%prep
%setup -q

%build
%configure
make %{?_smp_mflags}
make check

%install
rm -rf $RPM_BUILD_ROOT
#mkdir -p $RPM_BUILD_ROOT%{PACKAGE_HOME}/conf
#mkdir -p $RPM_BUILD_ROOT%{PACKAGE_HOME}/include
#mkdir -p $RPM_BUILD_ROOT%{PACKAGE_HOME}/lib
#cp -r conf/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/conf
#cp -r include/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/include
#cp -r lib/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/lib
%makeinstall
install -p -m 0644 include/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/include
install -p lib/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/lib
install -p -m 0644 data/* $RPM_BUILD_ROOT%{PACKAGE_HOME}/data
# install -p -m 0644 doc/* $RPM_BUILD_ROOT%{_docdir}
# cp -rf doc/* $RPM_BUILD_ROOT%{_docdir}
# delete tmp file 
find $RPM_BUILD_ROOT%{PACKAGE_HOME} \( -name "Makefile*" \) -exec rm -rf '{}' \;
find $RPM_BUILD_ROOT%{_docdir} \( -name "Makefile*" \) -exec rm -rf '{}' \;
rm -rf `find $RPM_BUILD_ROOT%{PACKAGE_HOME} -name ".svn*"`
rm -rf `find $RPM_BUILD_ROOT%{_docdir} -name ".svn*"`

%clean
rm -rf $RPM_BUILD_ROOT

%post
ldconfig

%postun
ldconfig

%files
%defattr(-,root,root,-)
#%doc AUTHORS COPYING ChangeLog INSTALL NEWS README
%{_libdir}/*.so*
%attr(755,root,root) %{_bindir}
%config(noreplace) %attr(666,root,root) %{_sysconfdir}
#%{_infodir}
#%{_mandir}
#%config(noreplace) %attr(666,root,root) %{PACKAGE_HOME}/conf/*
%{PACKAGE_HOME}/include/*
%{PACKAGE_HOME}/lib/*

%files devel
%defattr(-,root,root,-)
%{_includedir}
%{_libdir}/*.a
%{_libdir}/*.la
%{_libdir}/pkgconfig/*.pc

%files data
%defattr(-,root,root,-)
%{PACKAGE_HOME}/data

%files doc
%defattr(-,root,root,-)
%{_docdir}

%changelog
* Thu Jul 30 2009 Cnangel <junliang.li@alibaba-inc.com> 0.0.2-2
- Improve version control and add data package;
- Add LT_MAJOR, LT_REVISION and LT_AGE like lib*.so.1.0.0 ;
- Add DOXYGEN_OUTPUT_DIR doc/doxygen;
- Add doc/doxygen to rpm;
- Add test, you can use Check for c or Cppunit for c++;
- Add *.pc.in for pkgconfig;
* Mon Jun 08 2009 Cnangel <junliang.li@alibaba-inc.com> 0.0.1-1
- build the spec file.

# -fin-
