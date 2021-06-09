# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Axel Gembe <derago@gmail.com>
# Contributor: Oleksandr Natalenko <oleksandr@natalenko.name>
# Contributor: Antoine Lubineau <antoine@lubignon.info>

pkgname=dnsperf
pkgver=2.6.0
pkgrel=1
pkgdesc="Tools that measure performance of authoritative Domain Name services"
arch=('x86_64')
url="https://www.dns-oarc.net/tools/dnsperf"
license=('Apache')
depends=('bind' 'ldns' 'libck')
source=("https://www.dns-oarc.net/files/${pkgname}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('7d5e0a41798b02b634ad80401b71efe51ff5cfe3c07e1030149cf5772c45b72e')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./configure --prefix=/usr --mandir=/usr/share/man
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
}

