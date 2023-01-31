# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Martin Devera <devik@cdi.cz>

pkgname=sysstat
pkgver=12.7.2
pkgrel=1
pkgdesc="a collection of performance monitoring tools (iostat,isag,mpstat,pidstat,sadf,sar)"
arch=('x86_64')
url="http://pagesperso-orange.fr/sebastien.godard/"
license=('GPL')
depends=('lm_sensors')
makedepends=('systemd')
optdepends=('tk: to use isag'
	    'gnuplot: to use isag')
options=('zipman')
backup=('etc/conf.d/sysstat'
	'etc/conf.d/sysstat.ioconf')
source=("https://github.com/sysstat/sysstat/archive/refs/tags/v${pkgver}.tar.gz"
	'lib64-fix.patch')
sha512sums=('c9dbde263122c4adc0d22769a1ba69c9011bc8264a9298c0c2fcd3262a785e9cef34b69bb84ddc2bafbf11de5f2110946bbe7e88a98f03f99524894a5c02e0de'
            '6caae9962a636e5152b0462d0dce835d8f658848723bee2d7ac903a0f170a491882c819457c882bcee41159960fa243fb843a2389c9a4ceeea061a5520e01103')

prepare() {
  cd "${srcdir}"/"${pkgname}"-"${pkgver}"
  patch -p1 < "${srcdir}/lib64-fix.patch"
  autoreconf
}

build() {
  cd "${srcdir}"/"${pkgname}"-"${pkgver}"
  conf_dir=/etc/conf.d ./configure --prefix=/usr \
	--mandir=/usr/share/man \
	--enable-install-cron \
	--enable-copy-only \
  --disable-compress-manpg
  # patch makefile for FULL RELRO builds
  sed -e 's|CFLAGS = |CFLAGS += \$(CPPFLAGS) |' -e 's|LFLAGS = |LFLAGS = $(LDFLAGS) |' -i Makefile
  make
}

package() {
  cd "${srcdir}"/"${pkgname}"-"${pkgver}"
  mkdir -p "${pkgdir}"/usr/lib/systemd/system
  make DESTDIR="${pkgdir}" install
  chown -R root:root "${pkgdir}"
  rm -rf "${pkgdir}"/etc/rc*
}
