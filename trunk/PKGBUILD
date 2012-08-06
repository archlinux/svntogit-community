# $Id$
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org>

pkgbase=linux-tools
pkgname=('perf' 'cpupower' 'x86_energy_perf_policy' 'usbip')
pkgver=3.5
pkgrel=2.1
license=('GPL2')
arch=('i686' 'x86_64')
url='http://www.kernel.org'
options=('!strip')
# split packages need all package dependencies set manually in makedepends
# kernel source deps
makedepends=('asciidoc' 'xmlto')
# perf deps
makedepends+=('perl' 'python2' 'libnewt' 'elfutils')
# cpupower deps
makedepends+=('pciutils')
# usbip deps
makedepends+=('glib2' 'sysfsutils')
groups=("$pkgbase")
source=("http://ftp.kernel.org/pub/linux/kernel/v3.x/linux-$pkgver.tar.xz"
#        "http://ftp.kernel.org/pub/linux/kernel/v3.x/patch-$pkgver.4.xz"
        'cpupower.rc'
        'cpupower.conf'
        'cpupower.systemd'
        'cpupower.service')
md5sums=('24153eaaa81dedc9481ada8cd9c3b83d'
         '1d9214637968b91706b6e616a100d44b'
         '857ccdd0598511e3bf4b63522754dc48'
         'c0d17b5295fe964623c772a2dd981771'
         '2450e8ff41b30eb58d43b5fffbfde1f4')

build() {
  # apply stable patching set
  if (( NOEXTRACT == 0 )) && [[ -e "$srcdir"/patch-* ]]; then
    msg2 'Applying stable patch set'
    patch -N -p1 -i "$srcdir"/patch-*
  fi

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
  ./autogen.sh
  ./configure --prefix=/usr
  make
  popd
}

package_perf() {
  pkgdesc='Linux kernel performance auditing tool'
  depends=('perl' 'python2' 'libnewt' 'elfutils')

  cd linux-$pkgver/tools/perf
  make \
    WERROR=0 \
    DESTDIR="$pkgdir/usr" \
    perfexecdir='lib/perf' \
    PYTHON=python2 \
    NO_GTK2=1 \
    PERF_VERSION=$pkgver-$pkgrel \
    install install-man
}

package_cpupower() {
  pkgdesc='Linux kernel tool to examine and tune power saving related features of your processor'
  backup=('etc/conf.d/cpupower')
  depends=('bash' 'pciutils')
  conflicts=('cpufrequtils')

  pushd linux-$pkgver/tools/power/cpupower
  make \
    DESTDIR="$pkgdir" \
    mandir='/usr/share/man' \
    docdir='/usr/share/doc/cpupower' \
    install install-man
  popd
  # install rc.d script
  install -Dm 755 $pkgname.rc "$pkgdir/etc/rc.d/$pkgname"
  install -Dm 644 $pkgname.conf "$pkgdir/etc/conf.d/$pkgname"
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

  cd linux-$pkgver/drivers/staging/usbip/userspace
  make install DESTDIR="$pkgdir"
}

# vim:set ts=2 sw=2 ft=sh et:
