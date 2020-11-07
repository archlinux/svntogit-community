# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Martin Devera <devik@cdi.cz>

pkgname=sysstat
pkgver=12.4.0
pkgrel=2
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
source=("http://pagesperso-orange.fr/sebastien.godard/${pkgname}-${pkgver}.tar.xz"
	      'lib64-fix.patch'
        'fe7e338e20f5f533d460f9151eba20250857c350.patch')
sha512sums=('68314a50d3ab97c9e0cba27964b83cbc21bf08730a6ca9da655ecbeb574fc8fd83ea69038ec5c66a2b0bb367975f6cf45db840fe8dce69ddc64e64a35d6a1823'
            '46ec3eebb12232d30cddba60f16a57cd8d625513cf002d9e501797a6660f9da9cb4116ec81d0c292644fb6d91eb05c7be458da667260b238bcfef532a020b114'
            'ed6cb88e8036f9edc364a194b68b26829d70d40b60d4357cb15cd1b29c7583f563e2cc72f83bfd16e76cf0e08eea3095c035091bb848482ab4aa9e1e0200ff99')

prepare() {
  cd "${srcdir}"/"${pkgname}"-"${pkgver}"
  patch -p1 < "${srcdir}/lib64-fix.patch"
  patch -p1 < "${srcdir}/fe7e338e20f5f533d460f9151eba20250857c350.patch"
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
