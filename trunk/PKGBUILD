# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=rubydns
pkgname=ruby-${_gemname}
pkgver=2.0.2
pkgrel=5
pkgdesc='High-performance asynchronous DNS server and resolver'
url='https://github.com/ioquatix/rubydns'
arch=('any')
license=('MIT')
depends=('ruby' 'ruby-async-dns')
options=('!emptydirs')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/ioquatix/rubydns/archive/v${pkgver}.tar.gz)
sha256sums=('0e00588ad1d1c7fb4065c41e4d296f75be88c2479ab0399f85cdec8f4e7d5ac7')
sha512sums=('53b99038107af40acde2cbc776c1561d4e8ae155d709d3ba8f7200bdd805bbdc7753449005227d92f3d15618f87d290f7f7e23863934cb627ef130e026d2e1ce')

prepare() {
  cd ${_gemname}-${pkgver}
  sed 's|git ls-files|find|' -i ${_gemname}.gemspec
  sed 's|~>|>=|g' -i ${_gemname}.gemspec
  sed -r "s|(VERSION =) '2.0.1'|\1 '${pkgver}'|" -i lib/rubydns/version.rb
}

build() {
  cd ${_gemname}-${pkgver}
  gem build ${_gemname}.gemspec
}

package() {
  cd ${_gemname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  cp -r examples "${pkgdir}/usr/share/doc/${pkgname}"
  rm "${pkgdir}"/${_gemdir}/cache/${_gemname}-${pkgver}.gem
}

# vim: ts=2 sw=2 et:
