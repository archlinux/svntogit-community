# Contributor: L42y <423300@gmail.com>
# Maintainer: Christian Hesse <mail@eworm.de>

pkgname=oath-toolkit
pkgver=1.12.3
pkgrel=1
pkgdesc="The OATH Toolkit attempts to collect several tools that are useful when deploying technologies related to OATH"
arch=('i686' 'x86_64')
url="http://www.nongnu.org/oath-toolkit/"
license=('GPL')
depends=('pam')
source=("http://download.savannah.nongnu.org/releases/${pkgname}/${pkgname}-${pkgver}.tar.gz")

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"

  ./configure --prefix=/usr
  make
}

package() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  make DESTDIR="${pkgdir}/" install

  # Install basic docs too
  install -D -m 644 pam_oath/README ${pkgdir}/usr/share/doc/oath-toolkit/PAM_README
  install -D -m 644 README ${pkgdir}/usr/share/doc/oath-toolkit/README
}

sha256sums=('6409174084ae79389fb5b4081cf1fa663331c5ddae49e401a3f98afe59518417')
