# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=sass
pkgname=ruby-sass
pkgver=3.7.4
pkgrel=3
pkgdesc='Sass makes CSS fun again'
url='https://sass-lang.com/'
arch=('any')
license=('MIT')
depends=('ruby' 'ruby-sass-listen' 'ruby-yard' 'ruby-maruku' 'ruby-rdoc')
options=('!emptydirs')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/sass/ruby-sass/archive/${pkgver}.tar.gz)
sha256sums=('b39602cac4a5a09c621610ca369e7af97c7ae9f620bddfcd9423c6520de77626')
sha512sums=('4bebb6ddc84e7f2687d9b801e6b30e897d83a46940249349d775e0139d1fca8ffd96d0976f4c35a7a0dba9ebf786883a70aff2ff002708e28b685a034634aaf2')

prepare() {
  cd ${pkgname}-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec # don't give a fuck about rubys bla bla
}

build() {
  cd ${pkgname}-${pkgver}
  gem build ${_gemname}.gemspec
}

package() {
  cd ${pkgname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 MIT-LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"
}

# vim: ts=2 sw=2 et:
