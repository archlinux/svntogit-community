# $Id$
# Maintainer: Sébastien Luttringer

pkgbase=linux-tools
pkgname=('linux-tools-meta'
         'libtraceevent'
         'perf'
         'cpupower'
         'x86_energy_perf_policy'
         'usbip')
[[ $CARCH == i686 ]] && pkgname+=('lguest')
pkgver=3.7
pkgrel=6
license=('GPL2')
arch=('i686' 'x86_64')
url='http://www.kernel.org'
options=('!strip')
# split packages need all package dependencies set manually in makedepends
# kernel source deps
makedepends=('asciidoc' 'xmlto')
# perf deps
makedepends+=('perl' 'python2' 'libnewt' 'elfutils' 'audit' 'libunwind')
# cpupower deps
makedepends+=('pciutils')
# usbip deps
makedepends+=('glib2' 'sysfsutils')
groups=("$pkgbase")
source=("http://ftp.kernel.org/pub/linux/kernel/v3.x/linux-$pkgver.tar.xz"
        "http://ftp.kernel.org/pub/linux/kernel/v3.x/patch-$pkgver.6.xz"
        'cpupower.default'
        'cpupower.systemd'
        'cpupower.service'
        'usbipd.service')
md5sums=('21223369d682bcf44bcdfe1521095983'
         'ec61c44f37585a768d41c0439101ef9c'
         '56883c159381ba89e50ab8ea65efec77'
         '7e0710c2f31c1eb1e1417a7972e676b1'
         '2450e8ff41b30eb58d43b5fffbfde1f4'
         'a8fb0c6159bee1b9e345a87cabb3ba27')

build() {
  # apply stable patching set
  if (( NOEXTRACT == 0 )) && [[ -e "$srcdir"/patch-* ]]; then
    msg2 'Applying stable patch set'
    patch -N -p1 -i "$srcdir"/patch-*
  fi

  msg2 'Build libtraceevent'
  pushd linux-$pkgver/tools/lib/traceevent
  make
  popd

  msg2 'Build perf'
  pushd linux-$pkgver/tools/perf
  make \
    WERROR=0 \
    DESTDIR="$pkgdir/usr" \
    perfexecdir='lib/perf' \
    PYTHON=python2 \
    NO_GTK2=1 \
    PERF_VERSION=$pkgver-$pkgrel \
    all man
  popd

  msg2 'Build cpupower'
  pushd linux-$pkgver/tools/power/cpupower
  # we cannot use --as-needed
  LDFLAGS=${LDFLAGS:+"$LDFLAGS,--no-as-needed"}
  make VERSION=$pkgver-$pkgrel
  popd

  msg2 'Build x86_energy_perf_policy'
  pushd linux-$pkgver/tools/power/x86/x86_energy_perf_policy
  make
  popd

  msg2 'Build usbip'
  pushd linux-$pkgver/drivers/staging/usbip/userspace
  # fix missing man page
  sed -i 's/usbip_bind_driver.8//' Makefile.am
  ./autogen.sh
  ./configure --prefix=/usr
  make
  popd

  if [[ $CARCH == i686 ]]; then
    msg2 'Build lguest'
    pushd linux-$pkgver/tools/lguest
    make
    popd
  fi
}

package_linux-tools-meta() {
  pkgdesc='Linux kernel tools meta package'
  groups=()
  depends=('libtraceevent' 'perf' 'cpupower' 'x86_energy_perf_policy' 'usbip' 'lguest')
}

package_libtraceevent() {
  pkgdesc='Linux kernel trace event library'
  depends=('glibc')

  cd linux-$pkgver/tools/lib/traceevent
  install -dm 755 "$pkgdir/usr/lib"
  install -m 644 libtraceevent.a libtraceevent.so "$pkgdir/usr/lib"
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('perl' 'python2' 'libnewt' 'elfutils' 'audit' 'libunwind' 'binutils')

  cd linux-$pkgver/tools/perf
  make \
    WERROR=0 \
    DESTDIR="$pkgdir/usr" \
    perfexecdir='lib/perf' \
    PYTHON=python2 \
    NO_GTK2=1 \
    PERF_VERSION=$pkgver-$pkgrel \
    install install-man
  # move completion in new directory
  cd "$pkgdir"
  install -Dm644 usr/etc/bash_completion.d/perf usr/share/bash-completion/perf
  rm -r usr/etc
}

package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/default/cpupower')
  depends=('bash' 'pciutils')
  conflicts=('cpufrequtils')
  replaces=('cpufrequtils')
  install=cpupower.install

  pushd linux-$pkgver/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    mandir='/usr/share/man' \
    docdir='/usr/share/doc/cpupower' \
    install install-man
  popd
  # install startup scripts
  install -Dm 644 $pkgname.default "$pkgdir/etc/default/$pkgname"
  install -Dm 644 $pkgname.service "$pkgdir/usr/lib/systemd/system/$pkgname.service"
  install -Dm 755 $pkgname.systemd "$pkgdir/usr/lib/systemd/scripts/$pkgname"
}

package_x86_energy_perf_policy() {
  pkgdesc='Read or write MSR_IA32_ENERGY_PERF_BIAS'
  depends=('glibc')

  cd linux-$pkgver/tools/power/x86/x86_energy_perf_policy
  install -Dm 755 x86_energy_perf_policy "$pkgdir/usr/bin/x86_energy_perf_policy"
  install -Dm 644 x86_energy_perf_policy.8 "$pkgdir/usr/share/man/man8/x86_energy_perf_policy.8"
}

package_usbip() {
  pkgdesc='An USB device sharing system over IP network'
  depends=('glib2' 'sysfsutils')
  options=('!libtool')

  pushd linux-$pkgver/drivers/staging/usbip/userspace
  make install DESTDIR="$pkgdir"
  popd
  # module loading
  install -Dm 644 /dev/null "$pkgdir/usr/lib/modules-load.d/$pkgname.conf"
  printf 'usbip-core\nusbip-host\n' > "$pkgdir/usr/lib/modules-load.d/$pkgname.conf"
  # systemd
  install -Dm 644 usbipd.service "$pkgdir/usr/lib/systemd/system/usbipd.service"
}

package_lguest() {
  pkgdesc='Linux kernel x86 virtualization hypervisor'
  depends=('glibc')

  cd linux-$pkgver
  install -Dm 755 tools/lguest/lguest "$pkgdir/usr/bin/lguest"
  install -dm 755 "$pkgdir/usr/share/doc/$pkgname/"
  install -m 644 tools/lguest/lguest.txt "$pkgdir/usr/share/doc/$pkgname/"
  install -m 644 drivers/lguest/README "$pkgdir/usr/share/doc/$pkgname/"
}

# vim:set ts=2 sw=2 et:
