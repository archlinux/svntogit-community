# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Martin Devera <devik@cdi.cz>

pkgname=sysstat
pkgver=12.7.1
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
sha512sums=('5c1da0f5a1bf26091f029c5ea138f836616becb1e531843aa2c150a66ddc1f07b43cffeac98445855bf70319942fe22838a682c2f7685893bead7d8de7e9e2a8'
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
