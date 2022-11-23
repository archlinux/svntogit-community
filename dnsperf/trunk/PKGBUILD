# Maintainer: Konstantin Gizdov <arch at kge dot pw>
# Contributor: Axel Gembe <derago@gmail.com>
# Contributor: Oleksandr Natalenko <oleksandr@natalenko.name>
# Contributor: Antoine Lubineau <antoine@lubignon.info>

pkgname=dnsperf
pkgver=2.10.0
pkgrel=1
pkgdesc="Tools that measure performance of authoritative Domain Name services"
arch=('x86_64')
url="https://www.dns-oarc.net/tools/dnsperf"
license=('Apache')
depends=('ldns' 'libck' 'libnghttp2')
source=("https://www.dns-oarc.net/files/${pkgname}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('c4255f02b180299e5506cb5b130706a3ff8974426e4ed7a83852f3d8d11113fb')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  ./configure --prefix=/usr --mandir=/usr/share/man
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}" install
}
